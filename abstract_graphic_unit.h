#ifndef ABSTRACTGRAPHICUNIT_H
#define ABSTRACTGRAPHICUNIT_H

#include <memory>



/*!
 * \brief Класс HowToShow предназначен для запаковки графики в понятный для элемента viewer формат
 * \details Может представлять собой либо последовательность команд для векторной графики либо растовая картинка
 * \details Класс содержит в том числе геометрические размеры элемента
 */

class HowToShow{
    //TODO реализовать класс
};

using  HowToShow_ptr=std::shared_ptr<HowToShow>;

/*!
 * \brief enum Colors предназначен для кодирования цвета юнита
 */
enum Colors {
    RED=0,
    BLACK
    //TODO добавить поддерживаемые цвета
};


/*!
 * \brief Класс ContextMenuData предназначен для  заполнения контекстного меню юнита, вызываемого при нажатии правой кнопки мыши
 * \details Содержит указатели на методы с перечнем параметров и текстовыми обозначениями для пользователя
 */
class ContextMenuData {
    //TODO реализовать класс
};



/*!
 * \brief Класс AbstractGraphicUnit абстрактный базовый класс для всех графических юнитов, используемых в  редакторе
 */
class AbstractGraphicUnit
{


    float m_scale_x=1.0; //масштаб по оси x
    float m_scale_y=1.0; //масштаб по оси  y
    unsigned int m_x; //координата х левой верхней точки зоны занимаемой элементом
    unsigned int m_y; //координата y левой верхней точки зоны занимаемой элементом
    std::string m_name; //имя
    bool m_hightlight=false; //режим отображения подсвечен/не подсвечен
    Colors m_color =BLACK; //цвет отрисовки


    public:
    /*!
     * \brief Выдать координату х левой верхней точки зоны занимаемой элементом
     */
    unsigned int getX() {return m_x;}

    /*!
     * \brief Выдать координату y левой верхней точки зоны занимаемой элементом
     */
    unsigned int getY() {return m_y;}


    /*!
     * \brief Конструктор копирования для юнита
     * \param параметр other типа AbstractGraphicUnit& - юнит для копирования.
     */
    AbstractGraphicUnit(AbstractGraphicUnit& other)=default;

    /*!
     * \brief Функция копирования, принимающая на вход умный указатель
     * * \param параметр other типа std::shared_ptr<AbstractGraphicUnit>& - юнит для копирования.
     */
    virtual void copy(std::shared_ptr<AbstractGraphicUnit>& other)=0;

    /*!
     * \brief Установка параметров юнита
     * \param параметр name типа std::string - имя юнита.
     */
    virtual void rename (std::string name) {
        m_name=name;}


    /*!
     * \brief Предоставление информации для отрисовки юнита
     * \return Возвращает указатель типа HowToShow_ptr на класс, предоставляющий информацию об отрисовке
     */
    virtual HowToShow_ptr get()=0;


    //for GUI
    /*!
     * \brief Изменение масштабов юнита
     * \param параметр scale_x типа float - масштаб по оси x юнита.
     * \param параметр scale_y типа float - масштаб по оси y юнита.
     */
    virtual void scale(float scale_x, float scale_y)=0;

    /*!
     * \brief Изменение координат юнита
     * \param параметр x типа int- координата x юнита.
     * \param параметр y типа int- координата y юнита.
     */
    virtual void move(int x, int y)=0;

    /*!
     * \brief Изменение угла поворота юнита (относительно левого верхнего угла)
     * \param параметр angle типа float угол поворота в градусах

     */
    virtual void rotate(float  angle)=0;

    /*!
     * \brief Отражение относительно оси Х
     * \param параметр x типа int координаты оси для отражения
     */
    virtual void reflect_x(int x)=0;

    /*!
     * \brief Отражение относительно оси Y
     * \param параметр y типа int координаты оси для отражения
     */
    virtual void reflect_y(int y)=0;

    /*!
     * \brief Изменение цвета юнита
     * \param параметр c типа Colors кодирует цвет
     */
    virtual void setColor(Colors c){
        m_color=c;
    }


    /*!
     * \brief Получение данных для построения меню юнита
     * \return параметр типа ContextMenuData предоставляет информацию для построения контекстного меню элемента
     */
    virtual ContextMenuData& getMenuData()=0;


    /*!
     * \brief Включение и отключение режима подсветки юнита
     * \param  параметр on типа bool вкл/откл режи подсветки
     */
    virtual void hightLight(bool on) {
        m_hightlight=on;
    }



    virtual ~AbstractGraphicUnit();
};


using AbstractGraphicUnit_ptr=std::shared_ptr<AbstractGraphicUnit>;


#endif // ABSTRACTGRAPHICUNIT_H
