## About

**VineyardGuard** is an Open Sorce project, the main purpose of which is to automate vineyards' management. How to provide low cost, easy to build, and rugged components for optimizing agricultural irrigation and etc.? 
The idea for this project started from the necessity of smart control of irrigation system allowing remote control and economical use of water resources. Also for protection from parasitic birds during the ripening of the grapes.

The project consists of several independent modules, which are managed by a main module. The diagram below presents a block diagram of the current system. In the future each functional block of the system will be shown and described in more details.

![Core_diagram](https://github.com/iqnev/VineyardGuard/blob/master/Wiki/Core_Diagram.png)

**Sound system for protection of birds > Bird Block:**
***

 The main idea of this block is providing protection of birds of prey. For this purpose the current system provides a very simple approach that was taken from sound protection systems in airports. It is known that all birds are afraid of their carnivorous counterparts, such as eagle, falcon, hawk etc. 
This is the technology I have used in the last three years to guarding a vineyard. But the lack of more flexible mechanism of action forced me to implement the current technology in a smart appearance. 
This block consists of the following parts: a block to reading of the melodies and processing, a block for playing of the melodies.

**Monitoring soil moisture and irrigation management > Irrigation Block:**
***

This block provides mechanism for automated drip irrigation of the vineyard. Using soil moisture sensors you can determine when to start irrigation `S1, S2... SN`. 
The datа, that comes from these sensors are processed by the **>Main Block** and on basis of the values is decided whether to start supplying the water. To start or stop the water are used `Solenoid valves`, which are controlled from the main block. 
The modes of this block can be changed with a mobile device or by web interface. To this end, wireless communication is performed with the system.

In Development!
