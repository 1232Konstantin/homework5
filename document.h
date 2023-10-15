#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "abstract_graphic_unit.h"
#include <string>
#include <list>
#include "fabric.h"
#include "model.h"




/*!
 * \brief Класс Document имитирует координатную плоскость с расположенными на ней графическими юнитами
 * \details Реализует связь с фабрикой объектов и хранилищем данных. Сам в свою очередь предназначен для использования во viewer
 * \details Выполняет функции контроллера в модели MVC
 */
class Document
{
    std::list<AbstractGraphicUnit_ptr>  m_units; //перечень всех графических юнитов
    int m_width; //текущая ширина
    int m_height; //текущая высота
    Factory* m_factory; //указатель на фабрику юнитов
    Model* m_model; //указатель на хранилище

    public:

    /*!
     * \brief Конструктор
     * \param параметр fabric типа Factory* - указатель на фабрику объектов
     * \param параметр modelтипа Model - указатель на модель (хранилище информации)
     */
    Document(Factory* fabric, Model*model) : m_factory(fabric), m_model(model) {
        //TODO инициализировать документ
    }


    /*!
     * \brief Добавить юнит с заданным индексом, координатами и именем
     * \param параметр index типа int- индекс юнита на фабрике
     * \param параметр x типа int- координата x юнита.
     * \param параметр y типа int- координата y юнита.
     * \param параметр name типа std::string - имя юнита.
     */
    void addUnit(int index, int x, int y, std::string name="") {
        m_units.push_back(m_factory->createUnit(index, x, y, name));
        //TODO скорректировать размеры с учетом нового юнита (при необходимости)
    }

    /*!
     * \brief Удалить юнит
     * \param параметр unit типа AbstractGraphicUnit_ptr указатель на юнит.
     */
    void removeUnit(AbstractGraphicUnit_ptr& unit) {
        m_units.remove(unit);
    }

    /*!
     * \brief Получить перечень всех имеющихся графических юнитов
     * \return список типа std::list<AbstractGraphicUnit_ptr> содержащий указатели на юниты.
     */
    std::list<AbstractGraphicUnit_ptr>& getUnitList()  {
        return m_units;
    }

    /*!
     * \brief Перемещение группы юнитов
     * \param список типа std::list<AbstractGraphicUnit_ptr> содержащий указатели на юниты требующие перемещения.
     * \param параметр new_x типа int- смещение по x
     * \param параметр new_y типа int- смещение по y
     */
    void moveUnits( int new_x, int new_y, std::list<AbstractGraphicUnit_ptr> units){
        for (auto u: units) u->move(new_x,  new_y);
        //TODO скорректировать размеры (при необходимости)
    }

    /*!
     * \brief Удаление всех юнитов из документа
     */
    void clear(){
        m_units.clear();
    }

    /*!
     * \brief Выдать ширину документа
     * \return параметр типа int - ширина документа
     */
    int width() {
        //TODO реализовать вычисление ширины
        return m_width;}

    /*!
     * \brief Выдать высоту документа
     * \return параметр типа int - высота документа
     */
    int height() {
        //TODO реализовать вычисление высоты
        return  m_height;}

    /*!
     * \brief Загрузить в документ данные из файла
     * \param параметр filename типа std::string - имя файла
     */
    void loadFromFile(std::string filename) {
        m_units=m_model->load_from_file(filename);
        //TODO проверить все ли юниты загруженные из файла есть в фабрике, если нет выдать сообщение о несовпадении версий
    }


    /*!
     * \brief Сохранить данные в файл
     * \param параметр filename типа std::string - имя файла
     */
    void saveToFile(std::string filename) {
        m_model->save_to_file(filename, m_units);
    }


    /*!
     * \brief Получить перечень всех возможных юнитов с индексами и текстовыми описаниями (запрашиваем у фабрики)
     * \return список типа std::list<std::pair<int, std::string>> содержащий пары вида: индекс/описание элемента
     */
    std::list<std::pair<int, std::string>> get_unit_types()  {
        return m_factory->get_unit_types();
    }

        ~Document() {};
};

using Document_ptr=std::shared_ptr<Document>;

#endif // DOCUMENT_H
