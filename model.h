#ifndef MODEL_H
#define MODEL_H
#include "abstract_graphic_unit.h"
#include <string>
#include <list>


/*!
 * \brief Класс Model предназначен для работы с системой хранения (с файлами)
 * \details Представляет собой синглтон (указатель на модель доступен по вызову статической функции getInstance() )
 */
class Model
{
    inline static Model* m_model=nullptr;
    Model(){
        //TODO реализовать конструктор
    }
    Model(Model& other){}
    Model& operator=(Model&other){}
    ~Model() =default;
public:
    static Model* getInstance() {
        if (!m_model) m_model=new Model;
        return m_model;
    }

    /*!
     * \brief Загрузить данные из файла
     * \param параметр filename типа std::string - имя файла
     * \return список типа std::list<AbstractGraphicUnit_ptr> содержащий указатели на юниты
     */
    std::list<AbstractGraphicUnit_ptr> load_from_file(std::string filename){
        //TODO загрузить данные из файла
    }


    /*!
     * \brief Сохранить данные в файл
     * \param параметр filename типа std::string - имя файла
     * \param список типа std::list<AbstractGraphicUnit_ptr> содержащий указатели на юниты
     */
    void save_to_file(std::string filename, std::list<AbstractGraphicUnit_ptr> list){
        //TODO сохранить данные в файл
    }
};

#endif // MODEL_H

