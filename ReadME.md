# English 
### Why was it invented ?
1. To simplify line input and output in C++
2. So that everyone could use perfect input and output without complexity in encodings, locales, guides in 1 line
3. What would be clear even to a beginner

## Exemple how to connect
`#include "macros.h"` And that's it, did you think it would be more?

## What UnicodeStream can do
Exemple - ` dm::cxxout << "Hellow World!" << std::endl << "Привет Мир!" << std::endl << "世界您好" << std::endl << "Γεια σου κόσμε"; `

Out put - `Hellow World!
Привет Мир!
世界您好
Γεια σου κόσμε`
# Features:
- [x] cxxout for Windows platforms
- [] cxxin for Windows platforms (In progress)
- [] cxoout for Unix platforms
- [] cxxin for Unix platform
- [] Ability to color text

# How to Build: 
There are almost no dependencies **NO**, all you need is already in the project and all you need from you is C++20 and Cmake support and that's it

# Comment from the author
 This is my 1 serious project and it was inspired by the non-finishes when I was learning and doing a C++ project, I was doing (most likely will finish) a cli chat but I ran into a lot of problems with the standard 'iostream' and did it
 
  **If you see errors, write and I will try to fix it, but I will be grateful if you help and add a code solution**

# Русский
## Зачем было придуманно ?
 1. Упростить ввод и вывод строк в C++ 
 2. Чтобы каждый мог использовать нормальный ввод и вывод без сложностей в кодировках, локалях, гайдах все в 1 строке
 3. Что было бы понятно даже новичку
 ## Как подключить ? 
 `#include "macros.h"` И все, а вы думали будет больше ?

## Что может UnicodeStream ?
Например - ` dm::cxxout << "Hellow World!" << std::endl << "Привет Мир!" << std::endl << "世界您好" << std::endl << "Γεια σου κόσμε"; `

Вывидеться - `Hellow World!
Привет Мир!
世界您好
Γεια σου κόσμε`
# Функции:
- [x] cxxout для Windows платформ
- [] cxxin для Windows платформ (В работе)
- [] cxoout для Unix платформ
- [] cxxin для Unix плафторм 
- [] Возможность раскрашивать текст
# Как собрать:
Почти не каких зависимостей **НЕТУ** все что надо уже лежит в проекте и вам все что надо от вас это потдержка C++20 и Cmake и все
# Коментарий от автора
Это мой 1 серьезный проект и он был вдохновлен не достсткатками когда я изучал и делал проект на C++, я делал (Скорее всего доделаю) cli чат но я столкнулся с множеством проблем стандартого ` iostream ` и сделал это

**Если увидете ошибки напишите и я попробую исправить но буду благодарен если вы поможете и добавить код решение**