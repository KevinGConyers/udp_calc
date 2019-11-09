##COMPILATION INSTRUCTIONS

To compile and run the UDP calculation client and server, follow these instructions.

1. After unzipping the project folder, cd into it and delete the build directory **if one exists**
2. Run the *setup.sh* script (`./setup.sh`)
3. cd into the newly created build directory (`cd build`)
3. Run the server by typing `./ServerUDP [port]`
4. Run the client by typing `./ClientUDP [server address] [port]`

And then just use the calculation as outlined in the project description.

#notes:

***server address*** **MUST** be in dotted decimal notation (i.e. 127.0.0.1 for localhost).

If you encounter any issues please contact Kevin Conyers (kgc0019)  promptly, this code and build script have been tested *extensively* on the tux machines and have built and ran without issue. 
I do not want to lose points because of some minor misunderstanding in how the project should be built and ran.
