  # English 
  ### Why was it invented ?
  1. To simplify line input and output in C++
  2. So that everyone could use perfect input and output without complexity in encodings, locales, guides in 1 line
  3. To be simple and clear, even for beginners

  ## Example how to connect
  `#include "UnicodeStream.h"` And that's it, did you think it would be more?

  ## What UnicodeStream can do
  Example - ` dm::cxxout << "Hello World!" << std::endl << "Привет Мир!" << std::endl << "世界您好" << std::endl << "Γεια σου κόσμε"; `

  Output: ` Hello World! Привет Мир! 世界您好 Γεια σου κόσμε `
  # Features:
  - [x] cxxout for Windows platforms
  - [x] cxxin for Windows platforms 
  - [x] Ability to collect in the library 
  - [ ] cxxout for Unix platforms (Work in progress)
  - [ ] cxxin for Unix platform
  - [ ] Ability to color text

  # How to Build: 
  There are no external dependencies. Everything is already in the project.
  All you need is a compiler with `C++20` support and `CMake` — that’s it.

  `cmake ..` `cmake --build .`

  ### Connect 
  in CmakeLists.txt: 
  
   `find_package(UnicodeStream REQUIRED)` 
   
   `add_executable(MyApp main.cpp) `
   
   `target_link_libraries(MyApp PRIVATE UnicodeStream::UnicodeStream) `

  in .cpp :
  `#include "UnicodeStream/UnicodeStream.h"`
  


  # Comment from the author
  I was working on (and will most likely finish) a CLI chat project, but I ran into many problems with the standard iostream — so I created this.
  
  **If you see errors, write and I will try to fix it, but I will be grateful if you help and add a code solution**

  # Русский
  ## Зачем было придумано ?
  1. Упростить ввод и вывод строк в C++ 
  2. Чтобы каждый мог использовать нормальный ввод и вывод без сложностей в кодировках, локалях, гайдах все в 1 строке
  3. Что было бы понятно даже новичку
  ## Как подключить ? 
  `#include "UnicodeStream.h"` И все, а вы думали будет больше ?

  ## Что может UnicodeStream ?
  Например - ` dm::cxxout << "Hello World!" << std::endl << "Привет Мир!" << std::endl << "世界您好" << std::endl << "Γεια σου κόσμε"; `

  Выведется - `Hello World!
  Привет Мир!
  世界您好
  Γεια σου κόσμε`
  # Функции:
  - [x] cxxout для Windows платформ
  - [x] cxxin для Windows платформ 
  - [x] Возможность соберать в библиотеку 
  - [ ] cxxout для Unix платформ (В работе)
  - [ ] cxxin для Unix платформ 
  - [ ] Возможность раскрашивать текст
  # Как собрать:
  Почти никаких зависимостей **НЕТ** — всё что нужно, уже в проектеи вам все что надо от вас это поддержка `C++20 `и `Cmake` и все.

  `cmake ..` `cmake --build .`
  
  ### Для подключения
  в Cmake:
  
   `find_package(UnicodeStream REQUIRED)` 
   
   `add_executable(MyApp main.cpp) `
   
   `target_link_libraries(MyApp PRIVATE UnicodeStream::UnicodeStream) `
  
  в .cpp: `#include "UnicodeStream/UnicodeStream.h"`

  # Комментарий от автора
  Это мой 1 серьезный проект и он был вдохновлен не достсткатками когда я изучал и делал проект на C++, я делал (Скорее всего доделаю) cli чат но я столкнулся с множеством проблем стандартого ` iostream ` и сделал это

  **Если увидете ошибки напишите и я попробую исправить но буду благодарен, если вы поможете и предложите решение в коде**