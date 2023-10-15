#include <iostream>
#include "fabric.h"
#include "model.h"
#include "viewer.h"
#include "document.h"

using namespace std;

/*!
 * \brief Загрузить данные из файла
 * \param параметр filename типа std::string - имя файла
 * \param параметр document типа Document_ptr определяет документ с которым осуществляется процедура
 */
void openFile(Document_ptr document, std::string fileName){
    document->loadFromFile(fileName);
    //TODO Перерисовать весь document, сохранить имя открытого файла
}

/*!
 * \brief Сохранить данные в файл
 * \param параметр filename типа std::string - имя файла
 * \param параметр document типа Document_ptr определяет документ с которым осуществляется процедура
 */
void saveToFile(Document_ptr document, std::string fileName=""){
    document->saveToFile(fileName);
}





int main()
{
    auto fabric=Factory::getInstance();
    //TODO регистрируем в фабрике юниты наследники AbstractGraphicUnit

    auto l_ptr=std::shared_ptr<Document>(new Document(fabric, Model::getInstance()) );
    auto viewer=Viewer(l_ptr);

    auto ptr=viewer.addGraphicUnit(1, 0, 0); //добавляем юнит
    saveToFile(viewer.getDoc(), "File.dat");  //сохраняем в файл
    viewer.removeGraphicUnit(ptr); //удаляем юнит
    openFile(viewer.getDoc(), "File.dat"); //загружаем из файла


    return 0;
}
