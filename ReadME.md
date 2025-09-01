  # English 
  ## Why was it invented ?
  1. To simplify line input and output in C++
  2. So that everyone could use perfect input and output without complexity in encodings, locales, guides in 1 line
  3. To be simple and clear, even for beginners

  ## What UnicodeStream can do
  **Example** - ` dm::cxxout << "Hello World!" << std::endl << "Привет Мир!" << std::endl << "世界您好" << std::endl << "Γεια σου κόσμε"; `
  
  Output: ` Hello World! Привет Мир! 世界您好 Γεια σου κόσμε `

  **Advanced example** - `dm::cxxout << dm::Color::Red() << "Hello World!" << dm::Color::Blue() << std::endl << "Привет Мир!" << std::endl << dm::Color::Yellow() << "世界您好!" << std::endl << dm::Color::Cyan() << "Γεια σου κόσμε!" << dm::Reset::All();`

Output -  `Hello World! Привет Мир! 世界您好 Γεια σου κόσμε` 
**BUT** with different effects (For more effects, `Windows Terminal` on Windows is recommended)

  ## Example Connect 
  in CMakeLists.txt: 
  
   `find_package(UnicodeStream REQUIRED)` 
   
   `add_executable(MyApp main.cpp) `
   
   `target_link_libraries(MyApp PRIVATE UnicodeStream::UnicodeStream) `

  in .cpp :
  `#include "UnicodeStream.h"`
  
  And that's it, did you think it would be more?


  
  ## How to Build: 
  There are no external dependencies. Everything is already in the project.
  All you need is a compiler with `C++20` support and `CMake` — that’s it.

  `CMake ..` `CMake --build .` `CMake --install .`


  # Comment from the author
  I was working on (and will most likely finish) a CLI chat project, but I ran into many problems with the standard iostream — so I created this.

  # Features:
  - [x] cxxout for Windows platforms
  - [x] cxxin for Windows platforms 
  - [x] Ability to collect in the library 
  - [x] cxxout for Unix platforms (Need a check)
  - [x] cxxin for Unix platform (Need a check)
  - [x] Ability to color text
  - [ ] RGB color support (Work in progress)
  
  **If you see errors, write and I will try to fix it, but I will be grateful if you help and add a code solution**

  # Русский
  ## Зачем было придумано ?
  1. Упростить ввод и вывод строк в C++ 
  2. Чтобы каждый мог использовать нормальный ввод и вывод без сложностей в кодировках, локалях, гайдах все в 1 строке
  3. Что было бы понятно даже новичку

  ## Что может UnicodeStream ?
  **Простой пример** - ` dm::cxxout << "Hello World!" << std::endl << "Привет Мир!" << std::endl << "世界您好" << std::endl << "Γεια σου κόσμε"; `

  Выведется - `Hello World!
  Привет Мир!
  世界您好
  Γεια σου κόσμε`

  **Продвинутый пример** - `dm::cxxout << dm::Color::Red() << "Hello World!" << dm::Color::Blue() << std::endl << "Привет Мир!" << std::endl << dm::Color::Yellow() << "世界您好" << std::endl << dm::Color::Cyan() << "Γεια σου κόσμε" << dm::Reset::All();`
  
  Выведеться - `Hello World!
  Привет Мир!
  世界您好
  Γεια σου κόσμε` **НО** с разными эфектами (Для большего количества эффектов рекомендуется `Windows Terminal` на Windows)

 ### Для подключения
  в CMake:
  
   `find_package(UnicodeStream REQUIRED)` 
   
   `add_executable(MyApp main.cpp) `
   
   `target_link_libraries(MyApp PRIVATE UnicodeStream::UnicodeStream) `
  
  в .cpp: `#include "UnicodeStream.h"`
  
  И все, а вы думали будет больше ?

  # Как собрать:
  Почти никаких зависимостей **НЕТ** — всё что нужно, уже в проекте вам все что надо от вас это поддержка `C++20 `и `CMake` и все.

  `CMake ..` `CMake --build .` `CMake --install .`
  
  # Комментарий от автора
  Это мой 1 серьезный проект и он был вдохновлен недостатками когда я изучал и делал проект на C++, я делал (Скорее всего доделаю) cli чат но я столкнулся с множеством проблем стандартного ` iostream ` 

  **Если увидите ошибки напишите и я попробую исправить но буду благодарен, если вы поможете и предложите решение в коде**

  # Функции:
  - [x] cxxout для Windows платформ
  - [x] cxxin для Windows платформ 
  - [x] Возможность собирать в библиотеку 
  - [x] cxxout для Unix платформ (Надо проверка)
  - [x] cxxin для Unix платформ (Надо проверка)
  - [x] Возможность раскрашивать текст 
  - [ ] Поддержка RGB цветов (В работе)
  