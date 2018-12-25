#include "QRProcessor.h"



QRProcessor::QRProcessor() 
{
}

void QRProcessor::process(const cv::Mat& frame)
{
	ResultSet rs;
	rs.frame = frame;
	rs.state = State::START;
	rs.edge_col = rs.edge_row = 0;
	std::vector<ResultSet> rstack;
	while ( rs.state != State::FINISHED) 
	{
		PluginPtr& plugin(plugins[rs.state]);
		ResultSet newrs = rs;
		if (plugin->process(newrs)) {
			// update
			rstack.push_back(rs);
			rs = newrs; 
		}
		else {
			// rollback
			rs = rstack.back();
			rstack.pop_back();
		}
	}
}

QRProcessor::Plugin::Plugin(QRProcessor & p)
	: processor(p)
{
}

//////////////////////////////////////
class QRInitializerPlugin : public QRProcessor::Plugin
{
public:
	QRInitializerPlugin(QRProcessor& p) : QRProcessor::Plugin(p) {}
	virtual bool process( QRProcessor::ResultSet& rs ) override {
		if (rs.frame.empty()) return false;
		const int ncols = rs.frame.cols;
		for ( int j = 0; j < rs.frame.rows; ++j) {
			cv::Mat row = rs.frame.row(j);
			unsigned int start = 0;
			unsigned int count = 0;
			for ( int k = 0; k < ncols; ++k) {
				uint32_t pixel = row.at<uint32_t>(k);
				std::cout << pixel << std::endl;
				if (pixel == 0) {
					count += 1;
					if (count > 500) {
						rs.edge_row = j;
						rs.edge_col = start;
						return true;
					}
				}
				else {
					start = k+1;
					count = 0;
				}
			}
		}
	}
private:

};