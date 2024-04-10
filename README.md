# Text-based RPG game 
[![AGPL License](https://img.shields.io/badge/IUST-Mathemati%20c:-blue.svg)](http://www.gnu.org/licenses/agpl-3.0)
```
                                                       
                                                                                       /===-_---~~~~~~~~~------____  
                                                                                      |===-~___                _,-' `
                                                         -==\\                        `//~\\   ~~~~`---.___.-~~      
                                                     ______-==|                        | |  \\           _-~`         
                                               __--~~~  ,-/-==\\                       | |   `\        ,'             
                                            _-~       /'    |  \\                      / /      \      /               
                                          .'        /       |   \\                    /' /        \   /'                
                                         /  ____  /         |    \`\. ______________/'  /          \/'                  
                                        /-'~    ~~~~~---__  |     ~-/~         ( )   /'        _--~`                   
                                                          \_|      /        _) | ;  ),   __--~~                        
                                                            '~~--_/      _-~/- |/ \   '-~ \                            
    _____   ______  _____________                          {\__--_/}    / \\_>-|)<__\      \                           
    ___  | / /_  / / /__  /___  /                           /'   (_/  _-~  | |__>--<__|      |                          
    __   |/ /_  / / /__  / __  /                           |   _/) )-~     | |__>--<__|      |                          
    _  /|  / / /_/ / _  /___  /___                         / /~ ,_/       / /__>---<__/      |                          
    /_/ |_/  \____/  /_____/_____/                        o-o _//        /-~_>---<__-~      /                           
                                                         (^(~          /~_>---<__-      _-~                            
   _________                                           ,/|           /__>--<__/     _-~                               
   __  ____/________________  _________              ,//('(          |__>--<__|     /                  .----_          
   _  / __ __  ___/  __ \  / / /__  __ \            ( ( '))          |__>--<__|    |                 /' _---_~\        
   / /_/ / _  /   / /_/ / /_/ /__  /_/ /         `-)) )) (           |__>--<__|    |               /'  /     ~\`\      
   \____/  /_/    \____/\__,_/ _  .___/        ,/,'//( (             \__>--<__\    \            /'  //        ||      
                               /_/            ,( ( ((, ))              ~-__>--<_~-_  ~--____---~' _/'/        /'       
                                            `~/  )` ) ,/|                 ~-_~>--<_/-__       __-~ _/                  
                                          ._-~//( )/ )) `                    ~~-'_/_/ /~~~~~~~__--~                    
                                           ;'( ')/ ,)(                              ~~~~~~~~~~                         
                                          ' ') '( (/                                                                   
                                            '   '  `
                                           
  ```
 

Welcome stronger, here is a text-based PRG (Player Role-Playing Game) developed by Null Group. In this game, you'll embark on an exciting journey as one of the unique characters available, each with their own abilities and specialties. Navigate through challenges, battles, and adventures in a quest for victory and glory!

        

## ◾️ Explanation 

 

The provided C++ code implements a text-based RPG game that offers players an immersive journey through exploration, combat encounters, shop interactions, and inventory management. Let's delve deeper into the mechanics and structure of the game:
 
- Character Classes:
 
Human: Represents the player character. It encompasses attributes such as health points (HP), attack power, defense, gold (currency), level, and experience points (XP). Players navigate the game world, engage in combat, and make decisions that influence their character's progression.
Enemy: Represents adversaries encountered during exploration or combat. The code includes a specific type of enemy, the "Zombie," which engages the player in combat encounters.
 
- Game Options:
 
Explore: Players venture into the game world, embarking on an unpredictable journey filled with various events and encounters. These events include finding items like healing potions, stumbling upon traps, discovering treasure chests containing gold, or encountering enemies like the Zombie. Exploration adds an element of unpredictability and excitement to the gameplay.
Shop: This option allows players to interact with an in-game shop. Although the specific shop mechanics are not detailed in the provided code, players likely have the opportunity to buy or sell items, potentially upgrading their gear or stocking up on supplies for future challenges.
View Inventory: Players can access their inventory, which stores items collected during exploration or obtained through shop interactions. Managing the inventory is crucial for strategic planning, as items like healing potions can be instrumental in surviving tough encounters.
Quit Game: Enables players to exit the game gracefully when they've had their fill of adventure.

- Gameplay Mechanics:

Combat: Combat is a central aspect of the game, offering players the chance to test their skills against enemies like the Zombie. During combat encounters, players can choose from various actions, such as attacking with their weapon, using healing potions to restore health, or inspecting their inventory for strategic advantages. Combat continues until either the player or the enemy is defeated, adding tension and excitement to the gameplay.
Experience and Leveling: Defeating enemies earns players experience points (XP), contributing to their character's progression. As players accumulate XP, they may level up, gaining increased stats and potentially unlocking new abilities or equipment. Leveling up represents the player character's growth and development throughout the game.
UI and Display Functions: The game utilizes the ncurses library to provide a graphical interface within the console environment. Functions are included to display vital information such as health bars, XP bars, player stats, and combat updates. These visual elements enhance the player's immersion and understanding of the game state.

- Libraries Used:
  
The code leverages various C++ libraries, including `<algorithm>`, `<cstdlib>`, `<ctime>`, `<iostream>`, `<limits>`, `<vector>`, as well as custom header files such as `"Character.h"`, `"Enemy.h"`, `"GameState.h"`, `"HealingPotion.h"`, `"Shop.h"`, `"Zombie.h"`, among others. Additionally, the code incorporates the ncurses library for console-based user interface functionalities.

- Overall Experience:
  
The game offers players a rich and engaging RPG experience, combining strategic decision-making, exploration, and thrilling combat encounters. Through its text-based interface and dynamic gameplay mechanics, players are transported to a world filled with adventure, challenges, and opportunities for growth. Whether navigating treacherous dungeons, haggling with merchants, or facing off against fearsome foes, players are sure to find excitement and satisfaction in their quest for glory. 
By providing players with meaningful choices, a sense of progression, and immersive storytelling, the game captivates their imagination and keeps them coming back for more epic adventures in the realm of the unknown.


## ◾️ Installation

Here is a installation Guide for Project from Git Repository:

🔘 Step 1: Clone the Repository

```bash
git clone <repository_url>
cd <repository_directory>
```

Replace <repository_url> with the URL of the Git repository and <repository_directory> with the desired directory name.
  
🔘 Step 2: Install SFML
SFML is a multimedia library, and it's required for the project. Follow the instructions below to install SFML: 

On macOS using Homebrew:
```bash
brew install sfml
```
On Ubuntu/Debian Linux:

```bash
Copy code
sudo apt-get install libsfml-dev
```
On other Linux distributions:
Install SFML from your package manager, or you can download and compile SFML from source.

On Windows:
Download SFML from the official website (https://www.sfml-dev.org/download.php) and follow the installation instructions.

🔘 Step 3: Install ncurses
ncurses is a library for creating text-based user interfaces. Follow the instructions below to install ncurses:

On macOS using Homebrew:
```bash
brew install ncurses
```

On Ubuntu/Debian Linux:
```bash
sudo apt-get install libncurses5-dev libncursesw5-dev
```
On other Linux distributions:
Install ncurses from your package manager.

On Windows:
You can download PDCurses for Windows from https://pdcurses.org/ and follow the installation instructions.

🔘 Step 4: Compile and Run
The project includes a Makefile for easy compilation. Open a terminal and navigate to the project directory, then run the following commands:

```bash
make
```
This command will compile the project.

```bash
./executable_name
```
Replace executable_name with the name of the executable generated by the compilation.

🔘 Step 5: Enjoy
You have successfully installed and run the project! 

Explore the features and functionalities of the application.


### Additional Notes:

- If you encounter any issues during the installation process, refer to the documentation of SFML and ncurses for troubleshooting.
- Make sure to have a compatible compiler installed on your system (e.g., g++ for C++ projects).
- If you have any questions or need further assistance, feel free to reach out to the project maintainers or the community for support.


## ◾️ Features

- Combat System: Players can engage in combat with enemies like zombies.
- Exploration: Players can explore environments with random events such as finding items, encountering enemies, or traps.
- Shop: Players can visit shops to buy and sell items.
  Inventory Management: Players can view and manage their inventory.

- Player Stats: Display of player statistics like health points (HP), attack, defense, gold, level, and experience points (XP).

- Leveling Up: Players gain experience points from defeating enemies and can level up.

- Random Events: Various random events occur during exploration, adding excitement to gameplay.




## ◾️ FAQ

#### ?


#### ?


### ? 




## 🔗 Feedback

We value your feedback! If you encounter any bugs, have suggestions for improvements, or simply want to share your gaming experience, please don't hesitate to reach out to us. <3

- [Liliarouhi](https://github.com/liliarouhi)
- [Mahsesol](https://github.com/Mahsesol)
- [Yousof Shahrabi](https://github.com/yousofs)
- [MohammadMahdi-Sharifbeigy](https://github.com/MohammadMahdi-Sharifbeigy)