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

#ifndef FACE_DETECT_FILTER_H
#define FACE_DETECT_FILTER_H

#include <QPointF>
#include <QList>
#include <QVariant>
#include <QVariantList>
#include <QAbstractVideoFilter>
#include <QVideoFilterRunnable>

//#include <opencv2/opencv.hpp>
//#include <opencv2/face.hpp>

#include "faceplusplus.h"

class FacePlusPlusFilter;

class  FacePlusPlusRunnable : public QVideoFilterRunnable {
public:
  static QString kStoragePath;

   FacePlusPlusRunnable(FacePlusPlusFilter* filter);

  void init();
  virtual QVideoFrame run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags flags);

private:
  QString storage_path_;

  FacePlusPlusFilter* filter_;
};

class FacePlusPlusFilter : public QAbstractVideoFilter {
  Q_OBJECT
public:
  QVideoFilterRunnable* createFilterRunnable();

private:
   FacePlusPlusRunnable* face_detect_runnable_;

signals:
};

#endif // FACE_DETECT_FILTER_H
