#ifndef FABRIC_H
#define FABRIC_H
#include "abstract_graphic_unit.h"
#include <string>
#include <list>


/*!
 * \brief Класс Factory это фабрика объектов для созданиия разных вариаций графических юнитов
 * \details Представляет собой синглтон (указатель на фабрику доступен по вызову статической функции getInstance() )
 * \details Всем поддерживаемым типам юнитов соответствует определенный индекс
 */
class Factory
{
    inline static Factory* m_Factory=nullptr;
    Factory() {
        //TODO реализовать конструктор
    }
    Factory(Factory& other){}
    Factory& operator=(Factory&other){}
     ~Factory() =default;
public:
    static Factory* getInstance(){
        if (!m_Factory) m_Factory=new Factory;
        return m_Factory;
    }

    /*!
     * \brief Создание графического юнита с заданным индексом
     * \param параметр index типа int- индекс юнита на фабрике
     * \param параметр x типа int- координата x юнита.
     * \param параметр y типа int- координата y юнита.
     * \param параметр name типа std::string - имя юнита.
     * \return указатель типа AbstractGraphicUnit_ptr на созданный юнит
     */
    AbstractGraphicUnit_ptr createUnit(int index, int x=0, int y=0, std::string name="") {
        //TODO реализовать метод
    }


    /*!
     * \brief Получить перечень всех возможных юнитов с индексами и текстовыми описаниями
     * \return список типа std::list<std::pair<int, std::string>> содержащий пары вида: индекс/описание элемента
     */
    std::list<std::pair<int, std::string>> get_unit_types()  {
        //TODO реализовать метод
    }


    /*!
     * \brief регистрация нового типа юнита для использования фабрикой
     * \param параметр unit типа AbstractGraphicUnit_ptr - юнит для регистрации на фабрике
     * \param параметр description типа std::string - описание нового юнита.
     * \return индекс полученный данным типом юнитов при регистрации
     */
    int registrate(AbstractGraphicUnit_ptr unit, std::string description){
        //TODO реализовать метод
    }

};

#endif // FABRIC_H
