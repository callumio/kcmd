kmd: src/views/MainWindow.cpp src/views/BrowseButton.cpp src/main.cpp 
	g++ `pkg-config --cflags gtkmm-3.0` -o kmd src/views/BrowseButton.cpp src/views/MainWindow.cpp  src/main.cpp `pkg-config --libs gtkmm-3.0` -Wall -O2