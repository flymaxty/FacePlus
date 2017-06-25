/**
 * Author: Ye Tian <flymaxty@foxmail.com>
 * Copyright (c) 2016 Maker Collider Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 */

#include "faceplusplus_filter.h"

#include <QFile>
#include <QDebug>
#include <QThread>

#include <QQmlApplicationEngine>

 FacePlusPlusRunnable:: FacePlusPlusRunnable(FacePlusPlusFilter* filter) {
  filter_ = filter;

  QQmlApplicationEngine engine;
  storage_path_ = engine.offlineStoragePath();
}

QVideoFrame  FacePlusPlusRunnable::run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags flags) {
  Q_UNUSED(flags);
  Q_UNUSED(surfaceFormat);

//  cv::Mat raw_image(input->height()*3/2, input->width(), CV_8UC1, input->bits());
//  cv::Mat rgb_image, gray_image, eqhist_image;
//  std::vector<cv::Rect> face_list;

//  cv::cvtColor(raw_image, rgb_image, cv::COLOR_YUV420p2BGR);

//  // cause the data struct difference between qvideoframe and mat
//  // we use rgb2420p, though the rgb_image is bgr type
//  cv::cvtColor(rgb_image, raw_image, cv::COLOR_RGB2YUV_I420);

  return *input;
}

QVideoFilterRunnable* FacePlusPlusFilter::createFilterRunnable() {
  if(face_detect_runnable_ == NULL) {
    face_detect_runnable_ = new  FacePlusPlusRunnable(this);
  }

  return reinterpret_cast<QVideoFilterRunnable*>(face_detect_runnable_);
}
