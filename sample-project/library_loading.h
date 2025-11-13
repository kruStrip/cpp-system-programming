#ifndef LIBRARY_LOADING_H
#define LIBRARY_LOADING_H

#include <dlfcn.h>
#include <string>
#include <memory>
#include <type_traits>
#include <stdexcept>

template <typename F>
concept IsFunc = requires
{
    std::is_function_v<F> == true;
};

/// @brief Класс для динамической загрузки разделяемых библиотек
class LibraryLoader final
{
    public:
    /// @brief Конструктор
    /// @param[in] name имя библиотеки (путь)
    /// @throws std::logic_error при ошибке загрузки библиотеки
    LibraryLoader(const std::string& name);

    /// @brief Деструктор
    /// @details Закрывает библиотеку
    ~LibraryLoader() noexcept;

    /// @brief Получить символ
    /// @tparam Symbol тип функции
    /// @param name имя функции
    /// @return Указатель на запрашиваемую функцию
    template <IsFunc Symbol>
    Symbol* get_symbol(const std::string& name)
    {
        void* symbol = dlsym(h, name.c_str());
        if (symbol == nullptr)
        {
            throw std::logic_error("Could not find symbol " + name);
        }

        return reinterpret_cast<Symbol*>(symbol);
    }

    private:
    void* h;
};

#endif // LIBRARY_LOADING_H