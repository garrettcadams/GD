/**

Game Develop - LinkedObjects Extension
Copyright (c) 2011 Florian Rival (Florian.Rival@gmail.com)

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution.

*/

#ifndef LINKEDOBJECTSTOOLS_H_INCLUDED
#define LINKEDOBJECTSTOOLS_H_INCLUDED
#include <string>
#include <map>
#include <vector>
class Object;
class RuntimeScene;

namespace GDpriv
{

namespace LinkedObjects
{

void GD_EXTENSION_API LinkObjects(RuntimeScene & scene, Object * a, Object * b, const std::string & ,const std::string & );
void GD_EXTENSION_API RemoveLinkBetween(RuntimeScene & scene, Object * a, Object * b, const std::string & ,const std::string & );
void GD_EXTENSION_API RemoveAllLinksOf(RuntimeScene & scene, Object * object);
bool GD_EXTENSION_API PickAllObjectsLinkedTo(RuntimeScene & scene, std::map <std::string, std::vector<Object*> *> mapOfAllObjectLists, std::vector<std::string> & alreadyDeclaredObjects, const std::string &, Object * object);
bool GD_EXTENSION_API PickObjectsLinkedTo(RuntimeScene & scene, std::map <std::string, std::vector<Object*> *> pickedObjectsLists, std::vector<std::string> & alreadyDeclaredObjects, const std::string &, Object * object, std::string linkedName);

}

}

#endif // LINKEDOBJECTSTOOLS_H_INCLUDED