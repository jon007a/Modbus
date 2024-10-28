import QtQuick
import QtQuick.Window

Rectangle {
    color: "#1E1E1E"
    width: 300; height: 300

    property real dialValue: 0 // Добавьте это свойство
    signal sendSpeedChange(real speed)  // Объявляем сигнал
    signal sliderValueChanged(int value)

    Dial {
        id: dial
        anchors.centerIn: parent
        value: dialValue // Используйте это свойство)

    }

    Rectangle {
        id: container
        property int oldWidth: 0
        anchors { bottom: parent.bottom; left: parent.left
            right: parent.right; leftMargin: 20; rightMargin: 20
            bottomMargin: 10
        }
        height: 16

        radius: 8
        opacity: 0.7
        antialiasing: true
        gradient: Gradient {
            GradientStop { position: 0.0; color: "gray" }
            GradientStop { position: 1.0; color: "white" }
        }

        onWidthChanged: {
            if (oldWidth === 0) {
                oldWidth = width;
                return
            }

            let desiredPercent = slider.x * 100 / (oldWidth - 32)
            slider.x = desiredPercent * (width - 32) / 100
            oldWidth = width
        }

        Rectangle {
            id: slider

            x: 1; y: 1; width: 30; height: 14
            radius: 6
            antialiasing: true
            gradient: Gradient {
                GradientStop { position: 0.0; color: "#424242" }
                GradientStop { position: 1.0; color: "black" }
            }

            MouseArea {
                           anchors.fill: parent
                           anchors.margins: -16
                           drag.target: parent; drag.axis: Drag.XAxis
                           drag.minimumX: 2; drag.maximumX: container.width - 32

                           onReleased: {
                               // Пересчитываем значение и отправляем сигнал в mainwindow
                               let value = (slider.x / (container.width - 32)) * 12000; // Значение от 0 до 12000
                               dialValue = value; // Обновляем значение для отображения на приборе
                               sendSpeedChange(value); // Отправляем сигнал изменения скорости
                               sliderValueChanged(value); // Отправляем сигнал изменения значения слайдера
                           }
                       }
                   }
               }
}
