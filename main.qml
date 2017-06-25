import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtMultimedia 5.5

ApplicationWindow {
  visible: true
  width: 640
  height: 480
  title: qsTr("Face Plus")

  Camera {
      id: camera
      deviceId: "0"
      imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash

      exposure {
          exposureCompensation: -1.0
          exposureMode: Camera.ExposurePortrait
      }

      flash.mode: Camera.FlashRedEyeReduction

      imageCapture {
          id: camera_cap
          onImageCaptured: {
              photoPreview.source = preview
              console.debug(camera_cap.capturedImagePath);
          }
      }
  }

  VideoOutput {
    width: 320
    height: 240
    source: camera
    focus : visible

      Keys.onPressed: {
        if (event.key === Qt.Key_Left) {
          camera_cap.capture();
        }
      }
  }

  Image {
      id: photoPreview
      x: 320
      y: 240
      width: 320
      height: 240
  }

}
