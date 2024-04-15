# Text-based RPG game 
[![MIT License](https://img.shields.io/badge/IUST-Mathematic-blue.svg)](http://www.gnu.org/licenses/agpl-3.0)
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
 
Welcome stronger, here is a text-based RPG developed by *Null Group*. In this game, you'll embark on an exciting journey as one of the unique characters available, each with their own abilities and specialties. Navigate through challenges, battles, and adventures in a quest for victory and glory!

## Features

- Three different version of the game: **Normal**, **Ncurses** library and **FTXUI** library.
- Combat System: Players can engage in combat with enemies like zombies and Human Enemies.
- Exploration: Players can explore environments with random events such as finding items, encountering enemies, or traps.
- Shop: Players can visit shops to buy and sell items. Inventory Management: Players can view and manage their inventory.
- Player Stats: Display of player statistics like HP, attack, defense, gold, level, and XP.
- Leveling Up: Players gain experience points from defeating enemies and can level up.

## Explanation 

### Character Classes:
 
**Human:** Represents the player character. It encompasses attributes such as HP, attack power, defense, gold, level, and XP. Players navigate the game world, engage in combat, and make decisions that influence their character's progression.
**Enemy:** Represents adversaries encountered during exploration or combat. The code includes a specific type of enemy, Zombie and Human Enemy, which engages the player in combat encounters.
 
### Game Options:
 
**Explore:** Players venture into the game world, embarking on an unpredictable journey filled with various events and encounters. These events include finding items like healing potions, stumbling upon traps, discovering treasure chests containing gold, or encountering enemies like the Zombie. Exploration adds an element of unpredictability and excitement to the gameplay.
**Shop:** This option allows players to interact with an in-game shop. Although the specific shop mechanics are not detailed in the provided code, players likely have the opportunity to buy or sell items, potentially upgrading their gear or stocking up on supplies for future challenges.
**View Inventory:** Players can access their inventory, which stores items collected during exploration or obtained through shop interactions. Managing the inventory is crucial for strategic planning, as items like healing potions can be instrumental in surviving tough encounters.

### Gameplay Mechanics:

**Combat:** Combat is a central aspect of the game, offering players the chance to test their skills against enemies like the Zombie. During combat encounters, players can choose from various actions, such as attacking with their weapon, using healing potions to restore health, or inspecting their inventory for strategic advantages. Combat continues until either the player or the enemy is defeated, adding tension and excitement to the gameplay.
**Experience and Leveling:** Defeating enemies earns players experience points (XP), contributing to their character's progression. As players accumulate XP, they may level up, gaining increased stats and potentially unlocking new abilities or equipment. Leveling up represents the player character's growth and development throughout the game.

### Libraries Used:
  
The code leverages various C++ libraries, including **ncurses** and **FTXUI** libraries for console-based user interface functionalities.

### Overall Experience:
  
The game offers players a rich and engaging RPG experience, combining strategic decision-making, exploration, and thrilling combat encounters. Through its text-based interface and dynamic gameplay mechanics, players are transported to a world filled with adventure, challenges, and opportunities for growth. Whether navigating treacherous dungeons, haggling with merchants, or facing off against fearsome foes, players are sure to find excitement and satisfaction in their quest for glory. 


## Installation

🔘 Step 1: Clone the Repository

```bash
git clone https://github.com/MohammadMahdi-Sharifbeigy/IUSTZ.git
cd IUSTZ/
```
  
🔘 Step 2: Install SFML 

SFML is a multimedia library, and it's required for the project. Follow the instructions below to install SFML: 

On macOS using Homebrew:
```bash
brew install sfml
```

On Ubuntu/Debian Linux:

```bash 
sudo apt-get install libsfml-dev
```

On Windows:
Download SFML from the official [website](https://www.sfml-dev.org/download.php) and follow the installation instructions.

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
You can download PDCurses for Windows from [here](https://pdcurses.org/) and follow the installation instructions.

🔘 Step 4: Install FTXUI

FTXUI is a library for building text-based user interfaces. Follow the instructions below to install FTXUI:

Clone the FTXUI repository:
``` bash
git clone https://github.com/ArthurSonzogni/ftxui.git
cd ftxui
mkdir build
cd build
cmake -B build # or cmake ..
make
sudo make install # To install the library on your system - Optional
``` 

🔘 Step 5: Compile and Run
The project includes a Makefile for easy compilation. Open a terminal and navigate to the project directory, then run the following commands:

```bash
make
./game
```
You have successfully installed and run the project! 

## Running the Game with Docker

**Prerequisites**

Make sure you have Docker installed on your system before proceeding with the steps below.

To install Docker on your system, follow the steps below:

### For Linux (Ubuntu/Debian):

🔘 Step 1 : Update your existing list of packages:

```bash
sudo apt update
```

🔘 Step 2 : Install the necessary packages to allow apt to use a repository over HTTPS

```bash
sudo apt install apt-transport-https ca-certificates curl software-properties-common
```
🔘 Step 3 : Add Docker’s official GPG key

```bash
curl -fsSL https://download.docker.com/linux/ubuntu/gpg sudo apt-key add -
```

🔘 Step 4 : Set up the Docker repository

```bash
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
```

🔘 Step 5 : Update the package database with Docker packages from the newly added repository

```bash
sudo apt update
```

🔘 Step 6 : Make sure you are installing from the Docker repo instead of the default Ubuntu repo

```bash
apt-cache policy docker-ce
```

🔘 Step 7 : **Install Docker**

```bash
sudo apt install docker-ce
```

🔘 Step 8 : Verify Docker installation by checking the version

```bash
sudo docker --version
```

🔘 Step 9 : Start the Docker service and enable it to start on boot

```bash
sudo systemctl start docker
sudo systemctl enable docker
```

### For Windows and macOS:

🔘 Step 1 : Download and install Docker Desktop from the official Docker website: Docker Desktop

🔘 Step 2 : Follow the installation instructions provided by the Docker Desktop installer.

🔘 Step 3 : Once installed, start Docker Desktop from your applications.

🔘 Step 4 : Docker should now be running on your system.

### Building and Running the Game with Docker

🔘 Step 1 : Clone the Repository

```bash
git clone https://github.com/MohammadMahdi-Sharifbeigy/IUSTZ.git
cd IUSTZ/
```

🔘 Step 2 : Build the Docker Image

```bash
docker build -t text-based-rpg .
```

🔘 Step 3 : Run the Docker Container:

```bash
docker run -it text-based-rpg
```

This will start the game within the Docker container, allowing you to interact with the text-based RPG game environment.

### Docker Compose
Alternatively, you can use Docker Compose for easier management of the container. Here’s how you can use the provided **compose-dev.yaml** file:

```bash
docker-compose -f compose-dev.yaml up
```

This will start the container with the necessary dependencies and configurations for running the game.

### Additional Notes:

- If you encounter any issues during the installation process, refer to the documentation of SFML and ncurses for troubleshooting.
- Make sure to have a compatible compiler installed on your system (e.g., g++ for C++ projects).
- If you have any questions or need further assistance, feel free to reach out to the project maintainers or the community for support.



- [Liliarouhi](https://github.com/liliarouhi)
- [Mahsesol](https://github.com/Mahsesol)
- [Yousof Shahrabi](https://github.com/yousofs)
- [Mohammad Mahdi Sharifbeigy](https://github.com/MohammadMahdi-Sharifbeigy)



https://github.com/MohammadMahdi-Sharifbeigy/IUSTZ/assets/154425249/a5b36736-752f-48e4-b93a-a44df1edab11




