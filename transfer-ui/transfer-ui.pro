include (transfer-ui.pri)

QMAKE_CXXFLAGS += -Werror
QMAKE_CXXFLAGS += -g 
QMAKE_CXXFLAGS += -O2
CONFIG += debug_and_release

TARGET = transfer-ui
TRANSLATIONS = transfer-ui.ts
DBUS_ADAPTORS    = dbus-xml/TransferUI.xml 


#enable new transfer ui changes
DEFINES += SHOW_HISTORY

DEPENDPATH  += ./src
INCLUDEPATH += ./inc ./src ./TransferUI

VPATH       += $$DEPENDPATH $$INCLUDEPATH

# installations configuration
target.path = /usr/bin

INCLUDEPATH += ../src ./TransferUI
SOURCES +=main.cpp             

pubheaders.path  = /usr/include/TransferUI
pubheaders.files = dbus-xml/TransferUI.xml TransferUI/*


# Install prf file for others to use
prf.path            = $$[QT_INSTALL_DATA]/mkspecs/features
prf.files           = transfer-ui.prf

# service file
tui_service_entry.path = /usr/share/dbus-1/services/
tui_service_entry.files = com.meego.transferui.service

INSTALLS           +=   target      \
                        prf         \
                        pubheaders  \
                        tui_service_entry
