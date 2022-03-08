# x64Structs
If you know the structure's value when debugging, It'll be very helpful to understand how it works. but x96dbg isn't perfectly offered the structures to you. so I'll maintain this repository for gathering the useful structure when we debug to the application:sunglasses:
# Usage
## Parsing Header(x96dbgStructurs32.h)
1. Git clone the repository that you prefer path.
2. Open the Struct tab in your x96dbg.
3. Parsing the header file.

   Mouse right click :arrow_right: click the 'Pase Header' :arrow_right: open the header file
4. Check the valid log that 'Types parsed'
5. Open to the visit type dialog.

   Mouse right click :arrow_right: click the 'Visit type'
6. Input the structurs name in the dialog.
7. Input the address that you want see in the dialog.
8. Finally, You can see the parsed structure. then you inspect the member's values for your enjoyable debugging:wink:
![usage_video](https://user-images.githubusercontent.com/84364089/157155415-2951fc74-9c70-4e31-b6b7-feb9b3130307.gif)
# Contributing
Please feel free to contribute! Issues and pull request are most welcome.
## Ruls
- Child structure has the prefix '_'
- Any structures must have these comments except child structure.
   - Link of the structure's definition in MSDN
   - Included header file
# References
[x64dbg Type System](https://x64dbg.com/blog/2016/12/04/type-system.html)
# Authors
*FullStackReverser* - [fullstackreverser](https://github.com/fullstackreverser) - [@FullStackRCE](https://twitter.com/FullStackRCE)
# License
x96Structus is distributed under the Apache License. See [LICENSE](LICENSE) for more information.