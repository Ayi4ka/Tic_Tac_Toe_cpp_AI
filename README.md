# Tic-Tac-Toe with AI / Крестики-нолики с ИИ

🎮 A classic **Tic-Tac-Toe** game built with C++, where the computer plays intelligently using the **Minimax algorithm**. The goal is to either beat the player or, at worst, achieve a draw — never lose!

🎮 Классическая игра **Крестики-нолики** на C++, где компьютер принимает решения с помощью **алгоритма Минимакс**. Его цель — выиграть у игрока или как минимум свести игру к ничьей. Проигрышей — не допускается.

---

## 🧠 Features / Возможности

- 🧑‍🤝‍🧑 Human vs. AI gameplay / Игра игрока против компьютера  
- 💻 Smart computer strategy with Minimax / Умная стратегия компьютера с Минимакс  
- 🚫 Computer never loses (if нет багов!) / Компьютер не проигрывает  
- 🎯 Input validation and game state handling / Проверка ввода и отслеживание статуса игры  
- 📃 Clear console rendering / Отрисовка игрового поля в консоли  

---

## 🧮 Topics Covered / Темы

| Topic (EN)                     | Тема (RU)                             |
|-------------------------------|---------------------------------------|
| Recursion & Minimax           | Рекурсия и алгоритм Минимакс          |
| Game logic and rules checking | Логика игры и проверка условий победы |
| Console UI                    | Интерфейс в консоли                   |
| Arrays                        | Работа с массивами                   |
| Turn-based game flow          | Пошаговый игровой процесс             |

---

## 💡 Gameplay Preview / Как играть

X - YOU O - Smart Machine | |
--+---+-- | |
--+---+-- | |
Enter cell number from 0 to 8:


- Игрок ходит первым (`X`)  
- Компьютер отвечает (`O`)  
- Побеждает тот, кто соберёт линию из трёх одинаковых символов  

---

## 🛠 Usage / Как запустить

### 🔧 Requirements / Требования

- Компилятор C++ (например, GCC, MSVC)  
- Терминал или IDE (Code::Blocks, Visual Studio, CLion и т.д.)  

### ▶️ Compilation Example / Пример компиляции

```bash
g++ tic_tac_toe.cpp -o tic_tac_toe
./tic_tac_toe
```

##✅ Status / Статус
✨ Completed and fully playable. Further improvements may include:
- GUI version (SFML/Qt)
- Difficulty levels
- Enhanced UI
