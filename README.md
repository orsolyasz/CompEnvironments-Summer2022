# SoulNet - Project Documentation 

_Immerse yourself in SoulNet, a virtual world made in your image. With a single touch, our all-new SoulStream™ technology understands your true essence and channels it into a world designed to stimulate emotions that satisfy your deepest needs and desires._

_Transcend your body, leave material problems behind, explore perfect inner peace._

_Take a glimpse of the future – try SoulNet today._

[![Title Cover that reads SoulNet](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Cover.png)](https://www.youtube.com/watch?v=XkymM3IcORg)
_Click image link for a short video documentation by Sali Mallat_

## The Experience

SoulNet is an interactive experience designed for 1-3 players that offers a critical exploration of the relationships between our engagement with virtual worlds and our control over our freedom. The interactive installation stages a fictional tech demo set in the near future, asking us to consider what parts of our physical reality we are willing to give up to experience a promised digital paradise.

![Three illumnated player stations in front of a blank grid projection on the wall](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Installation-1.png)  

The game uses a costum-designed physical interface consisting of a tracking headset with built-in headphones and two hand-activated stations to allow players to enter a virtual game projected in front of them. While the headset interaction allows for a very satisfying level of control, the hand stations intentionally are uncomfortable, especially over longer periods of use. Their low position requires the users to crouch or kneel, the distance between them is large enough to make users have to reach out or twist their arms, and the globe has teeth-like coverings on the front that hide the gel/goo material of the touch points inside.

![Closeups of a futuristic headset and hand touch stations](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Interface-1.png)  
_The hand stations and headsets used to control the game_

![Single player station showing two white hand sets with one headset in between](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Interface-2.png)  
_Play station for a single user_

In the virtual side, player's head movements control a floating ball on screen - as long as their hands stay hooked in to the stations. The game has no pre-defined goals or end point, but as users travel in space and collect 3D objects by colliding with them, their ball-avatars grow a longer and longer sparkling trail, which has a mesmerizing effect meant to encourage users to stay for long periods of time. If a player disconnects, their progress is completely lost after a 10 second warning of red lights, pulsating visuals, alarming sounds, and multiple voice messages demanding that the user stay. 

![Screengrab from the game showing a player's circle with a growing trail](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Screengrab-1.png)  
_The virtual game experience_


## Development Process Outline

This project was developed in an extremely collaborative fashion by a team of six incredible students and myself: Adam Cole, Lea Ho, Sali Mallat, Sixiong Sheng, Alexandre Tarek, Lexin Zhou, and Orsolya Szantho. 

The following document will outline the overall development process with a particular focus on my contributions. The term-long collaboration of our team started with weekly group meetings and individual/small group work sessions in the first few weeks, and about 2 full/large group work sessions as well as essentially daily individual and small group work in the final stretch. A lot of both conceptual as well as build development work was accomplished in several hour long group sessions, especially in terms of bringing physical, electronic, and digital elements together, and finalizing major design questions around materials (eg of the touchpoints, of the statinos, of the headsets etc) and gameplay. Individual/paired/small group sessions were where we each developed separate components for the overall concept that we envisioned, discussed, decided, and realized together.

The full final github repo can be accessed [here](https://github.com/adamdavidcole/unreal-free-float-game). This was mostly managed by Adam, with whom I shared and collaborated on a lot of the Arduino code, with further uploads definitely from Sali and likely from Alexandre, who did quite some independent work on the Unreal end. That said, I want to acknowledge the contributions of all group members in our several long sessions (a lot of which inlcuded at least some coding updates as well) as well as individual explorations into game mechanics, textures, and more, and reiterate just how much of a team work focused project this really was. 

###### Further bits of my solo parts of code and project development, as well as image documentation is in my own [repo](https://github.com/orsolyasz/CompEnvironments-Summer2022), and further (narrated) video documentation and images can be found in this [Google Drive folder](https://drive.google.com/drive/folders/1dg3IlSSaJ3ajuTHMqoBdHLw2Asj2eavg?usp=sharing). ######

## Inspiration and Initial Explorations

Our development process began with about two weeks of conversations around our interests, technology's role in society, and physical and virtual environments. Using a shared [Miro board](https://miro.com/app/board/uXjVO60UuBM=/) of initial ideas, we identified several shared themes and technical objectives to explore. 

![Image of inspirations showing several physically intense tech devices](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Inspo-1.png)  

My personal inspirations for this project largely stemmed from the current craze with the metaverse and its ideas and promises of fully digital "immersive" experiences, or a fully meta-connected lifestyle. I had several hesitations around these promises and hoped to create something that questions where virtual experiences might fall short to all that the physical world has to offer. My interests meant that from the beginning, I was highly focused on creating an experience that has virtual components along with a specific and intentional physical design. I was keen to explore how the player/participant's engagement with the game/experience can serve as a commentary on the relationship of these two spaces (physical/virtual reality) or on the ways in which we inevitably relate to both of these spaces even when we focus on only one (ie how a technological tool/experience is still unavoidably situated in physical space and always has very physical consequences or meanings).

## Interface and Environment Design

In the earlier phases of development, I signed up to focus on potential physical interface and layout designs along with several people, especially Alexandre and Lexin with whom we have had a number of collaborative sessions. In these sessions, we discussed, sketched, prototyped, and tested a number of potential plausible controller designs, and also focused a lot on the positions these controllers could force players into. Our main goal with this experimentation was to find at least one controller design idea that would provide a unique/novel way for users to engage with the virtual experience, while also being simple, streamlined, and flexible enough to be positioned in unusul ways and "trick" users into giving up comfort and other phsycial freedoms (eg moving around freely) in order to interact with our experience.

![White plastic under a 3D printer](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Joystick.png)  
_Initial custom joystick idea being 3d printed - didn't work in the end_

![Demonstrating possible positions for players, on the floor and standing up](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Positions.png)  
_Alexandre kneeling on the floor, and standing up, demonstrating positions for a potential hand piece design_ 

## Circuit Development

After a number of exploratory sessions, the team decided on creating an up to 3 player experience, using a gyroscope and a number of touchpoints for each of the three player stations. (We also agreed that if we felt it needed, we might change or vary this more later on, but that ended up being unnecessary.) We based this decision on having tested single sensors for pressure points, cap touch points, a gyroscope, potentiometers, a joystick, as well as basic keyboard interactions and a facial tracking interaction. We tried different configurations as well as discussing and physically mocking up different positions these sensors could be in, or bodyparts whose movements they could measure.

![Basic circuit with several sensors loosely hooked up](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Circuit-1.png)  
_Testing a very basic setup_

We felt that the gyroscope provided the most streamlined way to get users' movement data, from a number of potential placement points, while being integrated into a wearable design that could also add to our narrative. We were aiming to create the physical elements of our installation to create an experience that felt futuristic and limiting at the same time, and we saw a lot of potential for the wearable design to communicate these feelings.

![Basic circuit with several sensors loosely hooked up](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Circuit-2.png)  
_Very basic gyroscope prototype using a single band that can attach to various body parts_

I took on the role of designing and building our complete circuit for the physical components. This process included creating individual circuits and bits of code for each component, and then integrating all components for all player units - 6 hand stations with light feedback as well as 3 headsets.

Fairly early on, with Adam's lead we found a communication system between the Arduino and Unreal (our selected platform for the game itself) that used Serial communication from Arduino to Processing, and sent that info from Processing to Unreal through osc. As we knew we would start splitting up different parts of the game among ourselves, we agreed really early on to fix the signal format that the final arduino code sends out - so that any change on the arduino side either in the circuit or in the code would never have to mean any changes in the code later down the line. The arduino was decided to send out the following information all as integers and floats -- a number to decide if both hands are connected, and 2 numbers mapped to 0-1 of the head rotation on 2 axes per each player.

My code and circuit development is documented more thoroughly in the Google [folder](https://drive.google.com/drive/folders/1dg3IlSSaJ3ajuTHMqoBdHLw2Asj2eavg?usp=sharing), as well as illustrated below. 

One of the main challenges was finding out that our chosen gyroscope sensor is only able to take two different I2C addresses. As we were relying using I2C communication for all of our sensors (the 3 gyroscopes as well as the 3 MPR 121 cap sensors), we needed to come up with an alternative solution. The MPRs were okay as they have a wider range of options for addresses and they are all different from the gyro addresses that needed to stay open, so we really only had one single gyro that could not be connected to and read by the same Arduino. Still, we considered several different setups - using three different boards for each player and sending info wirelessly to the main computer, using BLEs directly on the headsets with built in bluetooth and gyro sensing and sending that info to several central board wired together (and many more).

In the end, even though this idea didn't really come up with my conversations with technical staff, I decided to simply use wired sensors connected to two arduinos wired together - the secondary one only getting info from the single outstanding gyro while the primary reads all the rest of the components. I picked this design as I realized all I really needed was a separate I2C bus that could be read somehow, and that it was easiest to just connect 2 Leonardos through their built in secondary hardware serial communication pins (pin 0 to pin 1 and pin 1 to pin 0, using Serial1 commands in the code).

![Basic circuit with two Leonardos connected to control an LED](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Circuit-3.png)  
_Two Leonardos set up for hardware serial communication through connecting pin 0 to pin 1_

Once the two Leonardos were connected, our main/"receiver" Arduino had two BNO055 gyroscopes (one with the default address 0x28, and the other with the ADR pin connected to 3V to set the address to 0x29), and three MPR121 capacitive sensors (one with the default address 0x5A, one with the ADDR pin connected to the SDA pin for the address 0x5C, and one with the ADDR connected to SCL for the address 0x5D). The secondary/"sender" Arduino had the only job of reading a BNO055 at the default address 0x28.

![Multiple BNO sensors set up to the two boards](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Circuit-4.png)  
_Functional circuit with 3 BNO gyroscope sensors_

![All sensors set up to the two boards](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Circuit-5.png)  
_Final functional circuit with all sensors_

![Circuit connected to a cardboard headset made up of circle layers horizontally stacked on a basic frame](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Circuit-6.png)  
_Final functional circuit connected to a basic headset design prototype_

Once I had all these elements wired up, I also had to merge all the different bits of code and in this process I wanted to organize our code file to be easy to navigate as well. I ended up creating separate tabs to contain all functions per sensor group, and in a later collab session we troubleshooted some coding Adam did for the LED feedback and organized those into separate tabs as well.

A further large chunk of my work was to figure out a clean solution for our wiring - both on the circuit level as well as for the overall installation. I decided to create 3-5 m long wires for each headset and each handset, and discussed in meetings -with Sali and others on the physical set design team- to make sure to have cuts for cabling to go into handset stations as well. The idea was to have the handset stations take in all cables at the bottom so they could be taped, while the headsets were designed to receive an audio cable as well as a compact/braided cable for the small gyroscope element to go inside. The goal was to keep everything as clean as possible, while also ensuring that the components are easy to unplug for transport and replug for installation - which also meant making the circuit board itself organized enough to keep track of any possible hardware issues.

![Montage showing long colorful braided/twisted cables with paper labels and pin-header connections](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Circuit-7.png)  
_Building insanely long cables with easy-to-plug connections, and mini boards for individual components and communication_

I have to note here that our original design was intended to detect all 5 fingers on each hand of each user - only allowing them to engage with the game when all their fingers are connected - but then ended up moving away from this idea for two major reasons. The main reason was a technical one: it seemed extremely difficult to get that many consistent, reliable readings from our sensors (using one 12 channel sensor per user), especially as the touchpoints on one hand had to be on significantly longer cables than on the hand whose stand contained the chip itself, making their sensitivity siginificantly different. While we were trying to troubleshoot solutions for this issue, we realized that the easiest way to solve our problem was to have a single touch point connected under all fingers on one hand (so 2 connections per player, one for each hand) - and we also realized that this solution was also probably the most accessible (eg for players with smaller hands or fewer fingers). After this issue was resolved as much as possible, we moved on to adding LED feedback as a nice but important final touch to our system (for which Adam created some basic color animations later on). For this, I was again in charge of creating all wiring and coming up with easy to install/deinstall connections for each set.

![Two Arduino Leonardos and several custom elements on a larger wooden plate, with several wires hooked in](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Circuit-8.png)  
_Full final circuit board_

In addition to developing the complete circuit, I was also in charge of handling the 3D printing of our components, learning to manage loading filament, restarting broken prints, etc, which meant monitoring these on the daily for nearly two weeks (we had a lot of long prints to complete) - up until the last week when others took over finishing this task while I produced all cables and board components.


## User Testing

Throughout our design process, we engaged in several user testing sessions - both in individual work while developing components on our own and in our shared group sessions. In these sessions, we all tried on the headset, initially just with a basic game structure (controlling a single circle on screen), tried different hand positions while using the headset to find our desired play levels and player layout, played in multiplayer mode to feel out what kinds of play can emerge in a basic game environment, and more. I have found these sessions essential both in making a lot of our conceptual decisions and even in figuring out practial questions around the height of hand sets, length of needed cables, size adjustability of headsets, needed size or placement for sensor components, and in keeping all team members focused on a strong unified concept that we constantly developed together in a really horizontal (non-hierarchical) way.

![User testing a rudimentary headset and hand position](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/User-1.png)   
_Early experiments included using a basic strap as a headset prototype_

![Multiple users with basic headsets, other team members smiling and observing](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/User-2.png)  
_Usertesting multiplayer mode of quick builds before manufacturing all components of the final intended design (cases and cables)_

Videos of several user testing sessions can be found [here](https://drive.google.com/drive/folders/1dXZpcb_tA_fM6Hg-V6uQY33sJEpeJvSo?usp=sharing).



## Audio "Engineering" (Trouble)

Additionally, I spent a frankly sad amount of time trying to find a good way to separate our unreal audio output into several different audio devices. Really early on in the process, I found a way to take our basic headphones apart (without damage, just by unscrewing two screws!) and so found a way for our intended headset design to incorporate the ear pads from these headphones for audio feedback. As our conversations evolved, and we realized we would potentially want to provide audio feedback when users disconnect or as they collide with objects to collect, I realized it could be a nice touch to separate audio to be user specific (so player 1 would only hear the sounds from their own collisions or the welcome and warnings for their own engagement).

As a first step, I checked out an audio interface (a zoom uac-8) that I had never used before and (after some struggle) got it running on my computer properly, being recognized as an 8-channel output device. My original idea was to try and use channels 1-6 for LR audio per each of our 3 players, and potentially use channel 7 to play any room audio (we had talked about either designing a room ambience or playing a loop that welcomes and invites people to try the installation). As we already had so many levels to our setup (arduino to processing to unreal), and as this aspect of the design was really more my personal interest than something that all of the team felt was really neccessary (in fact we intentionally deprioritized all digital and audio aspects over the actual circuit and controller build), I wanted to try to keep this solution within Unreal instead of using another external software (like fmod, which just seemed more complicated than what we had time to figure out).  

After several days of research and consulting with instructors, I got to a place where I definitely had the interface working correctly as a surround sound speaker (playing multichannel audio files in a media player resulted in all channels playing on the correct connected headphones/speakers), and I was able to import multichannel audio files into Unreal and have them recognized as such. I thought it might be a solution to have Unreal play multichannel soundfx with empty channels on players who didn't need to hear the sound (eg play a collision glitter sound effect with audio only on Ch1&2 when player one collides, play another glitter sound effect with audio only on ch3&4 when player two collides etc). Unfortunately, after another long bit of research, I had to find that there was apparently simply no way to have Unreal play surround sound audio on a Mac based on some information on the forum. It seemed like no matter what I did, Unreal always played all channels in a correctly recognzied multichannel audio file only on the first LR channel on my speaker setup - and the info I found seemed to confirm that macs are only. Unfortunately, as 6 out of the 7 people on our team are on Mac computers, we had already decided that we needed to stick to using a Mac machine for the installation.

At some points, I had considered trying to have processing play the audio files instead, but I soon found out it is only able to acces stereo devices anyway as well. Dishartened - especially since the Unreal forum is quite full of posts from the past 6+ years of people asking for functionality to assign audio player outputs to specific hardware channels, I had to change the plan and simply find a way to play the same output audio to several speakers at the same time (which was okay overall, as having separate audio experiences really was more just my personal dream than an essential part of our plan). For this, we simply had a miniamp connected to the central computer, and used 3 out of its 4 outputs to connect to long standard 3.5mm audio cables going directly to each headset. In the coding side, I consulted with Adam to introduce some more delay and ducking for scenarios in which several warning or welcoming voice tracks needed to play at the same time - we basically ensured that the first second or two of each clip had the most important information, that these would play without interruption even if a new sound effect is triggered, and that they would "duck" (fade to a much lower volume) after the first second or so when a new audio is triggered so always the last triggered audio would play the loudest, but still all of them would clearly be there.

In addition, as we had some time during the final installation in the space, I did also design a last minute welcome/ambience track for the space. For this, we borrowed a separate media player with a set of two speakers, which both only took XLR, so we had to connect with the most insane cable setup (given the limitations of what was available on campus and in a nearby audio equipment shop). 

![Crazy cable connections of many layers of adapters](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Audio-1.png)  

In the end, despite the disappointment of not getting even the surround sound "hack" (solution) work, I feel like the headsets with the same repeated audio signal were a great solution in terms of gameplay, and we achieved our main goal of separating players' aural experience from the overall space - to ensure active players are encouraged to hook in and that onlookers could not get the same experience without trying the game themselves. (As our main concept for the sound was to create further separation between the virtual and physical side and serve as further incentive ot stay in the game.)
 
## Final Installation

For the final showcase, my main focus was installing each component in a stable layout by figuring out ways to run and tape cables cleanly while providing a stable connection, as well as taping and securing each hand station and other physical elements in a clean fashion. I was in charge of re-connecting/physically installing each separate electric component, and making sure they all worked reliably on location - while also supervising other teams' install and making sure the space was clean and safe overall, as I was co-organizing the group exhibition itself as well.

![Clean semifinal setup ](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Semifinal-1.png)  
_Cables and stations were taped to provide enough space while securing elements_

This setup -although perhaps relying on a bit too much tape on the hand sets- held up really well for the final presentation. The stations stayed in place as intended and were overall really reliably functional - the only technical issue we encountered was the secondary board freezing out a couple of times, but it still overall worked for several hours continuously every day, and I made sure that the layout was such that the system became easy enough to restart (it once had to be restarted by a gallery invigilator not on the team and even that went flowingly).

![Final setup with several users playing the game](https://raw.githubusercontent.com/orsolyasz/CompEnvironments-Summer2022/main/Photos/Final-1.png)  


## Final Takeaways, Future Plans

Seeing our gallery audience interact and play with the experience we built was not only really satisfying but also really eyeopening in many ways. It was amazing to see how much people were shocked and disturbed by the handsets' jelly/gooey touch points, and also how enjoyable many users found the head rotation control - several players stayed for a really long time to try to build as long a trail in the game as possible, competition emerged among some players, while others were focused deeply on their own personal experience alone, and a lot of players commented not only on how unusal but also on how restricting the experience felt. 

That said, my one worry was that I started to wonder if perhaps the game became too  fun overall. Although I did talk to some users that reflected on some narrative elements that we were trying to hit -about the physical experience being limiting and the virtual reality being much bigger a promise than in real life- we also got a lot of feedback about the game being just fun or other ways to make it more fun, and I definitely hope we can focus on developing more ways to communicate a clearer narrative and maybe criticism around our ways of engaging with technology and imagining technologies of the future.

As next steps, we have been invited to an arcade games exhibition and have started submitting this piece to some local digital festivals as well. We are all really hoping the game could reach more people and want to try to develop it further - smoothing out some of the mentioned issues with the system crashing as well as perhaps finetuning the physical/digital interactions and their perception. Most importantly for me, I would really love to hear more about how different kinds of users are finding the experience and take that feedback to build on - whether in the further development of this project, or for furture designs and interactions.