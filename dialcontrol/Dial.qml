import QtQuick

Item {
    id: root
    property real value: 0

    width: 210; height: 210

    Image { source: "background.png" }

    //! [needle_shadow]
    Image {
        x: 96
        y: 35
        source: "needle_shadow.png"
        transform: Rotation {
            origin.x: 9; origin.y: 67
            angle: needleRotation.angle
        }
    }
    //! [needle_shadow]

    //! [needle]
    Image {
        id: needle
        x: 98; y: 33
        antialiasing: true
        source: "needle.png"
        transform: Rotation {
            id: needleRotation
            origin.x: 5; origin.y: 65
            //! [needle angle]
            angle: Math.min(Math.max(-130, (root.value / 12000) * 260 - 130), 130)

            Behavior on angle {
                SpringAnimation {
                    spring: 1.4
                    damping: .15
                }
            }
            //! [needle angle]
        }
    }
    //! [needle]

    //! [overlay]
    Image { x: 21; y: 18; source: "overlay.png" }
    //! [overlay]

    // Дисплей под иглой
    Text {
        id: displayText
        text: "0" // Начальное значение
        font.pixelSize: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: needle.bottom // Размещаем ниже иглы
        anchors.topMargin: 13 // Отступ от иглы
    }

    // Динамическое обновление текста на дисплее
    Connections {
        target: root
        onValueChanged: {
            displayText.text = Math.round(value) ; // Обновляем текст в соответствии со значением иглы
        }
    }
}
