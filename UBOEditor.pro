#QT      += core gui

CONFIG -= qt
CONFIG += console
CONFIG += c++11 sse2
QMAKE_LFLAGS += -static
QMAKE_LFLAGS_CONSOLE_DLL += -static

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

!equals(_PRO_FILE_PWD_, $${OUT_PWD}) {
    message(_PRO_FILE_PWD_: $$_PRO_FILE_PWD_)
    message(OUT_PWD: $$OUT_PWD)
    error(you is use shadow build)
}

DEFINES -= UNICODE _UNICODE
DEFINES += GLEW_STATIC

RC_ICONS += shader.ico

# platform
contains(QT_ARCH, i386) {
    PLATFORM = x86
}
else {
    PLATFORM = x64
}

# target
DESTDIR = bin/$${PLATFORM}
DLLDESTDIR = bin/$${PLATFORM}

# include and library directory
INCLUDEPATH += "include"
INCLUDEPATH += "include/imgui"
INCLUDEPATH += "include/imgui/backends"
LIBS += -L./lib
LIBS += -L./lib/gcc/$${PLATFORM}

INCLUDEPATH += "x:/include"
LIBS += -Lx:/lib/windows/gcc/$${PLATFORM}

# intermediate directory
CONFIG(debug, debug|release) {
    MOC_DIR = obj/Qt/$${PLATFORM}/debug/moc
    OBJECTS_DIR = obj/Qt/$${PLATFORM}/debug
    RCC_DIR = obj/Qt/$${PLATFORM}/debug/rcc
    UI_DIR = obj/Qt/$${PLATFORM}/debug/ui
} else {
    MOC_DIR = obj/Qt/$${PLATFORM}/release/moc
    OBJECTS_DIR = obj/Qt/$${PLATFORM}/release
    RCC_DIR = obj/Qt/$${PLATFORM}/release/rcc
    UI_DIR = obj/Qt/$${PLATFORM}/release/ui
}

LIBS += -lglew32static
LIBS += -lglfw3

# windows configure
win32 {
    CONFIG += embed_manifest_dll
    LIBS += -lopengl32 -lglu32
    LIBS += -lgdi32 -lgdiplus
    LIBS += -lole32 -loleaut32 -luuid -lcomdlg32 -ldwmapi -lwinmm
    #LIBS += -ld3dcompiler_47
}
unix {
}
macx {
}

SOURCES += \
    main.cpp \
    pch.cpp \
    src/imgui/backends/imgui_impl_glfw.cpp \
    src/imgui/backends/imgui_impl_opengl2.cpp \
    src/imgui/imgui.cpp \
    src/imgui/imgui_demo.cpp \
    src/imgui/imgui_draw.cpp \
    src/imgui/imgui_tables.cpp \
    src/imgui/imgui_widgets.cpp \
    ui.cpp \
    src/glcommon.cpp \
    src/ubo_editor.cpp \
    src/ubo_viewer.cpp

HEADERS += \
    pch.h \
    ui.h \
    src/glcommon.h \
    src/ubo_editor.h \
    src/ubo_viewer.h \
    vertex.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
