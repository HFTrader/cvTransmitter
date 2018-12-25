#pragma once
#include "opencv2/opencv.hpp"
#include <memory>


class QRProcessor
{
public:
	enum class State {
		START = 0,
		EXTRACTING,
		FINISHED
	};

	struct ResultSet {
		State state;
		uint32_t edge_row, edge_col;
		cv::Mat frame;
	};
	class Plugin
	{
	public:
		Plugin(QRProcessor& p);
		virtual bool process( ResultSet& rs ) = 0;
	protected:
		QRProcessor& processor;
	};

	QRProcessor();
	void process( const cv::Mat& frame );
private:
	using PluginPtr = std::shared_ptr<Plugin>;
	using PluginMap = std::map<State, PluginPtr>;
	PluginMap plugins;
protected:
};
