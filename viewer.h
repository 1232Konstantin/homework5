#ifndef VIEWER_H
#define VIEWER_H
#include "document.h"

/*!
 * \brief enum MOUSE_MODIFIER предназначен для определения нажатых кнопок мыши
 */
enum MOUSE_MODIFIER
{
  RIGHT_BUTTON_PUSHED =1,
  LEFT_BUTTON_PUSHED
};

/*!
 * \brief Класс Viewer предназначен для организации взаимодействия с пользователем
 * \details Выполняет отображение юнитов на экране, масштабирует изображение, перемещает окно просмотра, обеспечивает интеррактивное взаимодействие с пользователем по средством контекстных меню (класс меню не показан)
 * \details Класс должен взаимодействовать с обработчиком мыши посредством вызова соответствующих функций
 * \details Класс может быть расширен библиотекой элементов, поддерживающей Drag and Drop (класс библиотеки не показан)
 */
class Viewer
{

   int m_current_scale;  //текущий масштаб
   int m_viewport_position_x=0; //позиция вьюпорта (экрана пользователя) в координатах документа
   int m_viewport_position_y=0; //позиция вьюпорта (экрана пользователя) в координатах документа
   int m_viewport_width; //размер вьюпорта
   int m_viewport_hight; //размер вьюпорта
   std::string current_file_name; //имя текущего открытого файла
   Document_ptr m_document; //указатель на документ

   std::list<std::pair<int, std::string>> m_unit_types; //библиотека элементов


   std::list<AbstractGraphicUnit_ptr> selected_units; //выделенные юниты на экране


   /*!
    * \brief Служебная функция перерисовывающая прямоугольную зону на экране
    * \param параметр left_top_x типа int- координата x верхнего левого угла прямоугольной зоны.
    * \param параметр left_top_y- координата y верхнего левого угла прямоугольной зоны.
    * \param параметр right_bottom_x типа int- координата x нижнего правого угла прямоугольной зоны.
    * \param параметр right_bottom_y- координата y нижнего правогоугла прямоугольной зоны.
    */
   void reDrawRect(int left_top_x, int left_top_y, int right_bottom_x, int right_bottom_y){
       //TODO Перерисовать все элементы в заданной области
   }

public:
   /*!
    * \brief Конструктор
    * \param параметр document типа Document_ptr - указатель на документ
    */
    Viewer(Document_ptr document)
    {
        m_document=document;
        m_unit_types=m_document->get_unit_types();
        //TODO создать интерфейс пользователя, уведомить юзера о допустимых индексах для юнитов
    }

    //GUI
    /*!
     * \brief Масштабирование внутри видимой области
     * \param параметр value типа int- значение масштабного коэффициента в процентах
     */
    void zoom(int value) {
        //TODO сохранить данные для пересчета координат, перерисовать
    }

    /*!
     * \brief Перемещение видимой области относительно общих размеров document
     * \param параметр value типа int- относительная координата
     */
    void scroll_x(int value){
        //TODO сохранить данные для пересчета координат, перерисовать
    }


    /*!
     * \brief Перемещение видимой области относительно общих размеров document
     * \param параметр value типа int- относительная координата
     */
    void scroll_y(int value){
        //TODO сохранить данные для пересчета координат, перерисовать
    }

    /*!
     * \brief Реакция на однократное нажатие левой клавиши мыши
     * \param параметр  x типа int- координата курсора
     * \param параметр  y типа int- координата курсора
     */
    void mouseLeftButtonClick(int x, int y){
        //TODO Проверить есть ли в данной точке unit. Если есть подсветить/погасить его, используя метод unit->hightLight()
        //TODO Определить зону где произошли изменения и перерисовать ее
    }

    /*!
     * \brief Реакция на однократное нажатие правой клавиши мыши
     * \param параметр  x типа int- координата курсора
     * \param параметр  y типа int- координата курсора
     */
    void mouseRightButtonClick(int x, int y){
        //TODO Проверить есть ли в данной точке unit. Если есть показать его контекстное меню, используя метод unit->getMenuData()
    }


    /*!
     * \brief Добавление графического юнита с заданным индексом в выбранную точку
     * \details Должна осуществляться методом drag and drop из библиотеки элементов
     * \param параметр  x типа int- координата курсора
     * \param параметр  y типа int- координата курсора
     * \param параметр  index типа int- индекс нового юнита
     * \return указатель типа AbstractGraphicUnit_ptr на новый юнит
     */
    AbstractGraphicUnit_ptr addGraphicUnit(int index, int x, int y){
        m_document->addUnit(index, x, y);
        //TODO Определить зону где произошли изменения и перерисовать ее
    }

    /*!
     * \brief Удалить юнит
     * \param параметр unit типа AbstractGraphicUnit_ptr указатель на юнит.
     */
    void removeGraphicUnit(AbstractGraphicUnit_ptr unit){
        m_document->removeUnit(unit);
        //TODO Определить зону где произошли изменения и перерисовать ее
    }


    /*!
     * \brief Реакция на перемещение мышки с нажатыми кнопками
     * \details Обрабатывается перемещение с нажатой левой кнопкой как перемещение выделенных элементов
     * \param параметр  old_x типа int- старая координата курсора
     * \param параметр  old_y типа int- старая координата курсора
     * \param параметр  old_x типа int- новая координата курсора
     * \param параметр  old_y типа int- новая координата курсора
     * \param параметр  м типа MOUSE_MODIFIER- модификатор нажатия мыши
     */
    void mouseMove(int old_x, int old_y, int new_x, int new_y, MOUSE_MODIFIER m){
        //ТОDO если нажата левая кнопка мыши, то двигать все выделенные элементы методом document.moveUnits
        //TODO Определить зону где произошли изменения и перерисовать ее
    }

    //
    /*!
     * \brief Функция выделяющая все элементы в прямоугольной зоне (при помощи мыши)
     * \param параметр left_top_x типа int- координата x верхнего левого угла прямоугольной зоны.
     * \param параметр left_top_y- координата y верхнего левого угла прямоугольной зоны.
     * \param параметр right_bottom_x типа int- координата x нижнего правого угла прямоугольной зоны.
     * \param параметр right_bottom_y- координата y нижнего правогоугла прямоугольной зоны.
     */
    void select(int left_top_x, int left_top_y, int right_bottom_x, int right_bottom_y){
        //TODO найти все элементы в области, выделить, поместить в selected_units
        //TODO Определить зону где произошли изменения и перерисовать ее
    }

    /*!
     * \brief Функция выдающая указатель на текущий документ
     * \param параметр Document_ptr- указатель на текущий документ
     */
    Document_ptr getDoc() {
        return m_document;
    }

    ~Viewer()=default;
};

#endif // VIEWER_H
