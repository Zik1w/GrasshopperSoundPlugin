# Fsound Plugin

#Dependencies
FMOD 

#Spec
It is developed as a subclass from DDTools and aim to work with Unreal 4.23


#Description 
Fsound is a sound module aims to take advantage of the existing FMOD integration with Unreal Engine to perform variety of sound events based on what is happening in the game world. There are three major functions of this module:
** Trigger sound events (the most fundamental events are sound triggering, but events are more powerful and including mixing changes, level manipualtion, etc. ) from FMOD based on gameplay/logic for specific moments/actions
** Keep track and monitor the gamestate that will be used for 
** Oversee the multi-player game way for sound generation and replication process based on a server-client relationship


#API
Besides the interaction with the FMOD itself, this module intends to stand on its own, with things are running. The potential APIs include monitor the events that are triggering right now, as well as a monitor for the resource (both memory and CPU usage for streaming) that is used by the FMOD. (However, there is already a very detailed and powerful monitor/profiling tool from FMOD itself, so the potential need for such API should be further discussed.)