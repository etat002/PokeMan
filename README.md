
# PokéMan
 
 Authors:
 [Eddy Tat (etat002)](https://github.com/etat002/),
	[Joseph Rodriguez (jrodr033)](https://github.com/jrodr033),
	[Jason Houang (jhoua001)](https://github.com/haiselan)

## Project Description

PokeMan will be a Text-Based Role-Playing Game (RPG), similar to the game Pokemon.  We chose the text based game as our project because we are interested in game development and the idea of creating a game seemed fun, and like a good challenge.

We plan to use the following languages and tools:

* C++ - Programming Language
* [Git](https://git-scm.com) - Version Control System
* [GitHub](https://github.com) - Remote Version Control System
* [Vim](https://www.vim.org) - Command Line tool
* [Valgrind](https://www.valgrind.org) - Memory Management Tool
* [GoogleTest](https://google.github.io/googletest) - Unit Testing Tool

This project will utilize the terminal to output information for the user as well as prompts for interactions.  Output also will also provide prompts in battles related choices.  Input will be text based commands chosen from the corresponding prompts.

The game will the player loop from wild battles to trainer battles.  The player will have access to a collection of characters they can use in battles and have the opportunity to switch out characters in the pokehub.  There will be about ten different characters.  Players will be able to catch new characters. Character attributes, like health, speed, etc., will be randomized and can be upgraded as they increase in level.  Characters will have a type that will create an attack multiplier that is determined using the types from the characters from the battle.  Characters will have unique attacks.  Players will also have an inventory of potions and pokespheres that can be used in battle.  Storyline decisions may provide the player with special inventory items.

## Class Diagram

![UML diagram](https://user-images.githubusercontent.com/91521682/144064267-1113f769-ad04-445b-83a6-6a573a4459fa.png)

All character classes like Player and Character inherit from CharacterEntity.  CharacterEntity defines simple functions that are shared between player and character like getting and setting name.  This creates a composite pattern that allows us to treat Player objects and Character objects similarly.  This is useful when passing into the BigBattle class.

The Character class holds info that all characters inherit like type, attack strength, health, and description.  This class also contains Stategy classes that will be used to determine how each of the characters different attacks are setup.  It will also hold a Strategy for leveling up the character.  The class will also have the necessary getters and setters, so that the Strategy classes have the required information to do their job. There will be ten diferent character class one for each different type.

The AttackStrategy abstract class holds all the information neccessary for implementing a specific attack.  There will be unique attacks for each character class, as well as more generic attacks that many of the characters have.

The LevelStrategy abstract class is in charge of determining how fast a character levels up.  There will be three types of level up strategy: slow, medium, and fast.

The Item abstract class will define item name, definition, and action that the item does.  There will be two types of items potion, and pokesphere.  Potion will increase heath during battle and there will be three types, small, medium and large.  Pokesphere is used to catch pokeman, there are also three, common, rarem and master.

The player class will define the "player" the user will be during the game.  The player has vector of three pokeman, that can be updated.  The player also has vector of items to choose from during battle.  Opponents in battle will also be represent by a player class except when fighting wild pokeman in which case they will be represented by a Character subclass.

The BigBattle class is in charge of controlling the battle at large.  It has a user player, and opponent player that will be used to get pokenman and inventory info for the battles.  The Battle class will be in charge of the character vs character battle.  This involves determining which character has won the battle as well as displaying battle prompts and distributing damage.

Some design patterns we used includes the composite design pattern and the strategy design pattern. The composite design pattern is used in the program to create structure between the player and the other entities, such as opponents and pokemans one will encounter. We chose the composite pattern for this case because players and pokemans can interact the same as players and other in game players do during battle. Players also contain pokemans. The composite pattern allowed for us to pass in either a random pokeman as an encounter or an enemy player for the battle, rather than write two separate classes for them. The strategy pattern is used in the program to determine the growth level of each pokeman and the different attacks each pokeman is capable of performing. The strategy pattern was chosen for these features because it allows for variety with each pokeman being randomly generated without having to hard code the strategies for each pokeman.
 
 ## Screenshots
 
 ### Game Intro
 
 <img width="1191" alt="Intro" src="https://user-images.githubusercontent.com/91521682/144058307-582265f2-ebdc-4862-bb67-5bb8d4b126f9.png">
 
 ### Battle
 
 <img width="1191" alt="Battle" src="https://user-images.githubusercontent.com/91521682/144059271-487021de-8f91-43e2-b739-1a2d0f84e370.png">

### Inventory

<img width="1191" alt="Inventory1" src="https://user-images.githubusercontent.com/91521682/144060035-d2c3bb3e-100d-4b6b-8a45-ce85aba27235.png">
<img width="1191" alt="Inventory2" src="https://user-images.githubusercontent.com/91521682/144060059-06a36e27-d082-4509-891a-1b6ebdedf23c.png">

### Pokehub

<img width="1191" alt="Pokehub1" src="https://user-images.githubusercontent.com/91521682/144060141-6679cb9b-4c94-49ea-8496-154a560ef5a8.png">
<img width="1191" alt="Pokehub2" src="https://user-images.githubusercontent.com/91521682/144060166-82fb1035-7196-4275-882b-c53016a0cc04.png">

 
 ## Installation/Usage
 
 To install PokeMan, clone the repository by running git clone https://github.com/cs100/final-project-etat002-snaka033-jrodr033-jhoua001-1.git in your terminal.  Build the executable by running cmake . and then make.  Then run ./pokeman to start the game.
 
 ## Testing
 
 PokeMan was tested using unit tests for the different functions that make up the game.  Each class was built and tested at the same time to make sure that bugs would be caught as quickly as possible.  This also helps ensure that the game runs as expected.  We used googletest to test our program.  We also used Valgrind to make sure there were not any memory leaks.
 
