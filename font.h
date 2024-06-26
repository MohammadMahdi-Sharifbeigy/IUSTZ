#ifndef FONT_H
#define FONT_H
#include <string>
using namespace std;
const string You_Died = R"(
                                              ▓██   ██▓ ▒█████   █    ██    ▓█████▄  ██▓▓█████ ▓█████▄ 
                                               ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▒██▀ ██▌▓██▒▓█   ▀ ▒██▀ ██▌
                                                ▒██ ██░▒██░  ██▒▓██  ▒██░   ░██   █▌▒██▒▒███   ░██   █▌
                                                ░ ▐██▓░▒██   ██░▓▓█  ░██░   ░▓█▄   ▌░██░▒▓█  ▄ ░▓█▄   ▌
                                                ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░▒████▓ ░██░░▒████▒░▒████▓ 
                                                 ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒     ▒▒▓  ▒ ░▓  ░░ ▒░ ░ ▒▒▓  ▒ 
                                               ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░     ░ ▒  ▒  ▒ ░ ░ ░  ░ ░ ▒  ▒ 
                                               ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░     ░ ░  ░  ▒ ░   ░    ░ ░  ░ 
                                               ░ ░         ░ ░     ░           ░     ░     ░  ░   ░    
                                               ░ ░                           ░                  ░       
)";
const string Wasted = R"(
                                                    ▄▄▌ ▐ ▄▌ ▄▄▄· .▄▄ · ▄▄▄▄▄▄▄▄ .·▄▄▄▄  
                                                    ██· █▌▐█▐█ ▀█ ▐█ ▀. •██  ▀▄.▀·██▪ ██ 
                                                    ██▪▐█▐▐▌▄█▀▀█ ▄▀▀▀█▄ ▐█.▪▐▀▀▪▄▐█· ▐█▌
                                                    ▐█▌██▐█▌▐█ ▪▐▌▐█▄▪▐█ ▐█▌·▐█▄▄▌██. ██ 
                                                     ▀▀▀▀ ▀▪ ▀  ▀  ▀▀▀▀  ▀▀▀  ▀▀▀ ▀▀▀▀▀• 
)";
const string You_fallen = R"(
                           ▓██   ██▓ ▒█████   █    ██  ██▒   █▓▓█████      █████▒▄▄▄       ██▓     ██▓    ▓█████  ███▄    █ 
                            ▒██  ██▒▒██▒  ██▒ ██  ▓██▒▓██░   █▒▓█   ▀    ▓██   ▒▒████▄    ▓██▒    ▓██▒    ▓█   ▀  ██ ▀█   █ 
                             ▒██ ██░▒██░  ██▒▓██  ▒██░ ▓██  █▒░▒███      ▒████ ░▒██  ▀█▄  ▒██░    ▒██░    ▒███   ▓██  ▀█ ██▒
                             ░ ▐██▓░▒██   ██░▓▓█  ░██░  ▒██ █░░▒▓█  ▄    ░▓█▒  ░░██▄▄▄▄██ ▒██░    ▒██░    ▒▓█  ▄ ▓██▒  ▐▌██▒
                             ░ ██▒▓░░ ████▓▒░▒▒█████▓    ▒▀█░  ░▒████▒   ░▒█░    ▓█   ▓██▒░██████▒░██████▒░▒████▒▒██░   ▓██░
                              ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒    ░ ▐░  ░░ ▒░ ░    ▒ ░    ▒▒   ▓▒█░░ ▒░▓  ░░ ▒░▓  ░░░ ▒░ ░░ ▒░   ▒ ▒ 
                            ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░    ░ ░░   ░ ░  ░    ░       ▒   ▒▒ ░░ ░ ▒  ░░ ░ ▒  ░ ░ ░  ░░ ░░   ░ ▒░
                            ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░      ░░     ░       ░ ░     ░   ▒     ░ ░     ░ ░      ░      ░   ░ ░ 
                            ░ ░         ░ ░     ░           ░     ░  ░                ░  ░    ░  ░    ░  ░   ░  ░         ░ 
                            ░ ░                            ░                                                                
)";
const string TryAgain = R"(
                                 ▄▄▄█████▓ ██▀███ ▓██   ██▓    ▄▄▄        ▄████  ▄▄▄       ██▓ ███▄    █  ▐██▌ 
                                 ▓  ██▒ ▓▒▓██ ▒ ██▒▒██  ██▒   ▒████▄     ██▒ ▀█▒▒████▄    ▓██▒ ██ ▀█   █  ▐██▌ 
                                 ▒ ▓██░ ▒░▓██ ░▄█ ▒ ▒██ ██░   ▒██  ▀█▄  ▒██░▄▄▄░▒██  ▀█▄  ▒██▒▓██  ▀█ ██▒ ▐██▌ 
                                 ░ ▓██▓ ░ ▒██▀▀█▄   ░ ▐██▓░   ░██▄▄▄▄██ ░▓█  ██▓░██▄▄▄▄██ ░██░▓██▒  ▐▌██▒ ▓██▒ 
                                   ▒██▒ ░ ░██▓ ▒██▒ ░ ██▒▓░    ▓█   ▓██▒░▒▓███▀▒ ▓█   ▓██▒░██░▒██░   ▓██░ ▒▄▄  
                                   ▒ ░░   ░ ▒▓ ░▒▓░  ██▒▒▒     ▒▒   ▓▒█░ ░▒   ▒  ▒▒   ▓▒█░░▓  ░ ▒░   ▒ ▒  ░▀▀▒ 
                                     ░      ░▒ ░ ▒░▓██ ░▒░      ▒   ▒▒ ░  ░   ░   ▒   ▒▒ ░ ▒ ░░ ░░   ░ ▒░ ░  ░ 
                                   ░        ░░   ░ ▒ ▒ ░░       ░   ▒   ░ ░   ░   ░   ▒    ▒ ░   ░   ░ ░     ░ 
                                             ░     ░ ░              ░  ░      ░       ░  ░ ░           ░  ░    
                                                   ░ ░                                                         
)";
const string well2 = R"(

                                  ██╗    ██╗███████╗██╗     ██╗         ██████╗  ██████╗ ███╗   ██╗███████╗          
                                  ██║    ██║██╔════╝██║     ██║         ██╔══██╗██╔═══██╗████╗  ██║██╔════╝          
                                  ██║ █╗ ██║█████╗  ██║     ██║         ██║  ██║██║   ██║██╔██╗ ██║█████╗            
                                  ██║███╗██║██╔══╝  ██║     ██║         ██║  ██║██║   ██║██║╚██╗██║██╔══╝            
                        ██╗██╗    ╚███╔███╔╝███████╗███████╗███████╗    ██████╔╝╚██████╔╝██║ ╚████║███████╗    ██╗██╗
                        ╚═╝╚═╝     ╚══╝╚══╝ ╚══════╝╚══════╝╚══════╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝╚══════╝    ╚═╝╚═╝
)";
const string Well = R"(
                                               █     █░▓█████  ██▓     ██▓       ▓█████▄  ▒█████   ███▄    █ ▓█████              
                                              ▓█░ █ ░█░▓█   ▀ ▓██▒    ▓██▒       ▒██▀ ██▌▒██▒  ██▒ ██ ▀█   █ ▓█   ▀              
                                              ▒█░ █ ░█ ▒███   ▒██░    ▒██░       ░██   █▌▒██░  ██▒▓██  ▀█ ██▒▒███                
                                              ░█░ █ ░█ ▒▓█  ▄ ▒██░    ▒██░       ░▓█▄   ▌▒██   ██░▓██▒  ▐▌██▒▒▓█  ▄              
                                  ██▓  ██▓    ░░██▒██▓ ░▒████▒░██████▒░██████▒   ░▒████▓ ░ ████▓▒░▒██░   ▓██░░▒████▒    ██▓  ██▓ 
                                  ▒▓▒  ▒▓▒    ░ ▓░▒ ▒  ░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░    ▒▒▓  ▒ ░ ▒░▒░▒░ ░ ▒░   ▒ ▒ ░░ ▒░ ░    ▒▓▒  ▒▓▒ 
                                  ░▒   ░▒       ▒ ░ ░   ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░    ░ ▒  ▒   ░ ▒ ▒░ ░ ░░   ░ ▒░ ░ ░  ░    ░▒   ░▒  
                                  ░    ░        ░   ░     ░     ░ ░     ░ ░       ░ ░  ░ ░ ░ ░ ▒     ░   ░ ░    ░       ░    ░   
                                   ░    ░         ░       ░  ░    ░  ░    ░  ░      ░        ░ ░           ░    ░  ░     ░    ░  
                                   ░    ░                                         ░                                      ░    ░  
)";

     const string Wellcome1= R"(
                                                                                                    ______________                        
                                                                                              ,===:'.,            `-._                           
                                                                                                   `:.`---.__         `-._                       
    d8b   db db    db db      db         d888b  d8888b.  .d88b.  db    db d8888b.                    `:.     `--.         `.                     
    888o  88 88    88 88      88        88' Y8b 88  `8D .8P  Y8. 88    88 88  `8D                      |.        `.         `.                   
    88V8o 88 88    88 88      88        88      88oobY' 88    88 88    88 88oodD'              (,,(,    |.         `.   ____,-`.,                
    88 V8o88 88    88 88      88        88  ooo 88`8b   88    88 88    88 88                (,'     `/   |.   ,--.___`.'                         
    88  V888 88b  d88 88booo. 88booo.   88  ~8~ 88 `88. `8b  d8' 88b  d88 88            ,  ,'  ,--.  `,   | ;'         `                         
    VP   V8P 'Y8888P' Y88888P Y88888P    Y888P  88   YD  `Y88P'  ~Y8888P' 88             `{D, {    }  :    (;                                    
                                                                                           V,,'    /  /    //                                    
    Fighting RPG text_based game                                                           j;;    /  ,' ,-//.    ,---.      ,                    
                                                                                           (;'   /  ,' /  _  )  /  _  )   ,'/                    
                                                                                                 (   `'  / ]  `'  / ]  `.' /                     
                                                                                                  `.___,'   `.__,'   `.__,'                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    )";

    const string Wellcome2 = R"(
            _,..__
           `  '-. `'-.
                 \    '.
                 |      \                       
                 |      _\__    _         
             __ /     .' ___`;.` )       
            /  `'-.__/-'` ;---,'`
            \   .-'   ; // /=\=                
             `-/ / ; >   | \0|0_   
               );     ; /     __)   
               <    >  |    __|
               |  ;    <   `\_/           
               \   <   |  .--'                  
                )    > / /               
               | ;    (-'.                
               \   /  /-./        _          ██╗    ██╗███████╗██╗             ██████╗ ██████╗ ███╗   ███╗███████╗
               > ;   ;\   '.     / )         ██║    ██║██╔════╝██║            ██╔════╝██╔═══██╗████╗ ████║██╔════╝  
              /_ _.;-._|    '.  / /          ██║ █╗ ██║█████╗  ██║            ██║     ██║   ██║██╔████╔██║█████╗        
              ` ' |          / / /           ██║███╗██║██╔══╝  ██║            ██║     ██║   ██║██║╚██╔╝██║██╔══╝  
                  |   /   _.' / /           ╚███╔███╔╝███████╗███████╗        ╚██████╗╚██████╔╝██║ ╚═╝ ██║███████╗
                  |   |  /   / /             ╚══╝╚══╝ ╚══════╝╚══════╝         ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝
                 /|   |  |  / /   
                /  \   \ | / /    
              .'    \__/-./ /     
             /        \  \ /     
             |         '--/  
             |         / /                                                
              \       / /|       
               |     / / |      
               |    / /  |          
               |   / /   \         
               |  / /     |             _  _ _  _ _    _       ____ ____ ____ _  _ ___  
             ,/  / /      \             |\ | |  | |    |       | __ |__/ |  | |  | |__] 
            /'  / /        \            | \| |__| |___ |___    |__] |  \ |__| |__| |            
          .' _(`-;          |          
       .-' /_  `-.)         \           tab to start your advanture...
     .'  .'. `-._ |          |          
    /  ,-~ /`-,_ /           |         
   |  .-' ~ ~.'/`            /       
   '--,=~,-',-' `----'-----'`       
)";

const string Superhero1 = 
R"(
             .=.,
            ;c =\
          __|  _/
        .'-'-._/-'-._
       /..   ____    \
      /' _ ([NULL])   \
     (  / \--\_>/-/'._ )
      \-;_/\__;__/ _/ _/
       '._}|==o==\{_\/\
        /  /-._.--\  \ \
       // /   /|   \  \ \
      / | |   | \;  |  \ \
     / /  | :/   \: \   \_\
    /  |  /.'|   /: |    \ \
    |  |  |--| . |--|     \_\
    / _/   \ | : | /___--._) \
   |_(---'-| >-'-| |       '-'
          /_/     \_\
)";  //superhero


const string Superhero2 = R"(
                   ,,,,                       
             ,;) .';;;;',                     
 ;;,,_,-.-.,;;'_,(|);;;/),,_                  
  `';;/:|:);{ ;;;|| );/ /;;;[__               
      L;/-';/ {;;[',/;[/;;;.') ]              
      .:`''` - {;;'.__/;;;/  . _'-._          
    .'/   (     {;;;;;;/.'_7:.  '). ]_        
  .''/     ( '._ );}{;//.'    '-:  '.,L      
.'. /       (  ( |;;;/_/         (._./;]   _, 
 . /        |( ( /;;/_/             ';;;],;;_,
. /         )__(/;;/_/                (;;'''''
 /        _;:':;;;;:';-._             );      
/        /   (  `'`   --.'-._          V     
       .'     '.  ,'         '-,              
      /    /   r--,..__       '.]             
    .'    '  .'        '--._     ]            
    (     :.(;>        _ .' '- ;/             
    |      /:;(    ,_.';(   __.'              
     '- -''|;:/    (;;;;-'--'                 
           |;/      ;;(                       
           ''      /;;|                      
                   (;;|                     
                     V                        )";    //super hero

const string Paladin1 = 
R"(
  ,   A           {}
 / \, | ,        .--.
|    =|= >      /.--.\
 \ /` | `       |====|
  `   |         |`::`|
      |     .-;`\..../`;_.-^-._
     /\\/  /  |...::..|`   :   `|
     |:'\ |   /'''::''|   .:.   |
      \ /\;-,/\   ::  |..:::::..|
      |\ <` >  >._::_.| ':::::' |
      | `""`  /   ^^  |   ':'   |
      |       |       \    :    /
      |       |        \   :   /
      |       |___/\___|`-.:.-`
      |        \_ || _/    `
      |        <_ >< _>
      |        |  ||  |
      |        |  ||  |
      |       _\.:||:./_
      |      /____/\____\  
)"; // paladin


const string Paladin3 = 
R"(
       .-""-.
      /-.{}  \
      | _\__.|
      \/^)^ \/
       \ =  /
  .---./`--`\.--._
 /     `;--'`     \
;        /`       ;
|       |*        |
/   |   |     |    \
|    \  |*    /    |
\_   |\_|____/|  __/
  \__//======\\__/
  / //_      _\\ \
  -'  |`""""`|  `-
      |  L   |
      >_ || _<
      |  ||  |
      |  ||  |
     /   ||   \
    /    /,    \
     `|"|`"|"|"`
     /  )  /  )  
    /__/  /__/
)";  // paladin
 
const string Paladin2 = 
R"(
                 \\\\\//////
                \\\\\\//////
               [[[[[[[]]]]]]]]
               /////////\\\\\\
       /\     //// ~0 ( 0~ \\\\
      /  \    //(,  8-_\-8 ,)\\ 
     /    \    //|\ .===. /|\\
     |/||\|       \ '===' /*
       ||          \__.__/
    _.=||=._   .---'@   @'---.
    /| || |\  /     '@ @'     \
      _||_   /    .   Y   .  _/\
     /  _))-'  /|'---{@}---'|\_/\
     |  _)  _.' |   --:--   | \  \
     \___)-'    |   --:--   |  \  \
       ||       ;   --:--   ;  /  /
       ||        \____.____/  /  /
       ||      .{{{{{{{{}}}}}/ /`
       ||      {{{{{{{{{{{{{}} |
       ||      {}}}}}}}}}}}}}}_/
       ||      {{{{{{{{{{{{{{}  
       ||      {}}}}}}}}}}}}}}
       ||      '{}}}}}}}}}}}}'
       ||         |   |   |
       ||         |   |   |
       ||         |   |   |
       ||         |   |   |
       ||         |'-'|'-'|
       ||         |   |   |
       ||         |   |   |
       ||         |___|   |
       ||         (___)   }
       ||         /   |   \
       ||        (oooO Oooo)
)"; // paladin




const string Assassin1 = 
R"(
                    _
                    \`\
                     \ \
                      \ \
                       \ \
                        \.\
                         \.\
                          \.\  
                 _         \.\/)
            _ _-' ')__     (\.\/)
           /       /  \.'`'-\/)\\
           \__ ,.-'(_  Y    (_\.\)
            / <     ,\  \    ,\\.\\
            \_ \ _. /y(_|    : |\.\|
             _\_\\   |    : | \.\
            (   `'-._>/ )     \|  \.\
            \         `:=.    (\   \.\
             \_      (    `--._)`--'\.\=7
            _/|\_    \-._     `-:_ /```-3    
           /  |  `-   \  t--._    Y    _3 
        ,-'   |       /  |   /``'-.\--T x\
      _/     _(    ,./  /   (          \ x\
         _.-/  \  /    <     \          \ x\
      <`'  /   |\/      `-.   :          \_x\
       \  /    |           `. |
        \_|    /             `.
          |   /                `.
         /  _/\                /
)";  // assassin

const string Cyborg1 =
R"(
            _____
           X_____\
   .-^-.  ||_| |_||  .-^-.
  /_\_/_\_|  |_|  |_/_\_/_\
  ||(_)| __\_____/__ |(_)||
  \/| | |::|\```/|::| | |\/
  /`---_|::| NULL|::|_---'\
 / /  \ |::|-|-|-|::| /  \ \
/_/   /|`--'-+-+-`--'|\   \_\
| \  / |===/_\ /_\===| \  / |
|  \/  /---/-/-\-\  o\  \/  |
| ||| | O / /   \ \   | ||| |
| ||| ||----\ | /----|o|||| |
\/|\/  |     |||     |o|\/|\/
\_o/   |----|||||----|-' \o_/
       |##  |   |  ##|
       ||__ |   | __||
      [|'  `|] [|'  `|]
      [|`--'|] [|`--'|]
      /|__| |\ /| |__|\
      ||__|_|| ||_|__||
      \|----|/ \|----|/    
      /______\ /______\
      |__||__| |__||__|
)"; //cyborg

const string Wizard1 =
R"(
                    ____
                  .'* *.'
               __/_*_*(_
              / _______ \
            _\_)/&__&\(_/_
            / _((\- -/))_ \
            \ \())(-)(()/ /
             ' \(((()))/ '
            / ' \)).))/  ' \
           / _ \ - | -  /_  \
          (   ( .;''';.  .'  )
          _\"__ /      \ __"/_
            \/  \ NULL /  \/
             .'  '... ' ' )
              / /  |  \ \
             / .   .   . \
            /   .     .   \
           /   /   |   \   \
         .'   /    b    '.  '.
     _.-'    /     Bb     '-. '-._
 _.-'       |      BBb       '-.  '-.
.(________mrf\____.dBBBb.________)____)      
)";  // wizard

const string AsianMom1 = R"(
        w*W*W*W*w
         \"."."/
          //`\\
         (/a a\)
         (\_-_/) 
        .-~'='~-.
       /`~`"Y"`~`\
      / /(_ * _)\ \
     / /  )   (  \ \
     \ \_/\\_//\_/ / 
      \/_) '*' (_\/
        |       |
        |       |
        |       |
        |       |
        |       |
        |       |
        |       |
        |       |
        w*W*W*W*w     )"; // Asain mom

    
const string Sniper1 = R"(
   |\              
   || .---.       
   ||/_____\         
   ||(== ==)       
   || \_-_/_        
   :-"`'V'//-.       
  / ,   |// , `\   
 / /NULL//Ll|| |  
/_/||__//   || |  
\ \/---|[]==|| |  
 \/\__/ |   \| | 
 /\|_   | Ll_\ |  
 `--|`^"""^`||_|   
    |   |   ||/     
    |   |   | 
    |   |   |     
    |   |   |       
    L___l___J       
     |_ | _|       
    (___|___)    
     ^^^ ^^^           
)"; // Sniper


const string DeathAngel1 =
R"(
                                           .""--..__
                     _                     []       ``-.._
                  .'` `'.                  ||__           `-._
                 /    ,-.\                 ||_ ```---..__     `-.
                /    /:::\\               /|//}          ``--._  `.
                |    |:::||              |////}                `-. \
                |    |:::||             //'///                    `.\
                |    |:::||            //  ||'                      `|
                /    |:::|/        _,-//\  ||
               /`    |:::|`-,__,-'`  |/  \ ||
             /`  |   |'' ||           \   |||
           /`    \   |   ||            |  /||
         |`       |  |   |)            \ | ||
        |          \ |   /      ,.__    \| ||
        /           `         /`    `\   | ||
       |                     /        \  / ||
       |                     |        | /  ||
       /         /           |        `(   ||
      /          .           /          )  ||
     |            \          |     ________||
    /             |          /     `-------.|
   |\            /          |              ||
   \/`-._       |           /              ||
    //   `.    /`           |              ||
   //`.    `. |             \              ||
  ///\ `-._  )/             |              ||
 //// )   .(/               |              ||
 ||||   ,'` )               /              //
 ||||  /                    /             || 
 `\\` /`                    |             // 
     |`                     \            ||  
    /                        |           //  
  /`                          \         //   
/`                            |        ||    
`-.___,-.      .-.        ___,'        (/    
)"; //Death Angel

const string Zombie1 = 
R"( 

                .--.               .--.
               | = o\             | = o\
               \= =_/             \= =_/
                )= \____           )= \____
               ; = _|__-\         ; = _|__-\
               |= ----.\          |= ----.\
               ('.==|             ('.==|
              / \=\=\            / \=\=\
           _.'  /=/\=\_       _.'  /=/\=\_
  _____..-'    /__) \__)__..-'    /__) \__)
 

)";


#endif
