cmake_minimum_required(VERSION 2.8.12.2)

project(Server)
find_package(Threads)

add_executable(Server main.cpp KnnClassifier.h Classifiable.h Iris.h
        Iris.cpp ../tools.h ../tools.cpp TServer.cpp TServer.h metrics/Distance.h
        metrics/EuclideanDistance.h metrics/ChebyshevDistance.h metrics/ManhattanDistance.h commands/Command.h
        io/DefaultIO.h commands/UploadUnclassifiedCommand.h io/StandardIO.cpp
        io/StandardIO.h commands/ChangeSettingsCommand.h io/SocketIO.cpp io/SocketIO.h Matrix.cpp Matrix.h commands/ConfusionMatrixCommand.h
        ClientData.h commands/ClassifyDataCommand.h commands/DisplayResultsCommand.h CLI.h commands/DownloadResultsCommand.h)

target_link_libraries(Server ${CMAKE_THREAD_LIBS_INIT})
