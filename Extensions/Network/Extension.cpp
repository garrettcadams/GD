/**

Game Develop - Network Extension
Copyright (c) 2008-2010 Florian Rival (Florian.Rival@gmail.com)

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

#include "GDL/ExtensionBase.h"
#include "GDL/Version.h"
#include "NetworkActions.h"
#include "NetworkExpressions.h"
#include <boost/version.hpp>

/**
 * This class declare information about the extension.
 */
class Extension : public ExtensionBase
{
    public:

        /**
         * Constructor of an extension declares everything the extension contains : Objects, actions, conditions and expressions.
         */
        Extension()
        {
            DECLARE_THE_EXTENSION("Network",
                                  _("Fonctionnalit�s r�seau"),
                                  _("Extension permettant de communiquer entre plusieurs jeux"),
                                  "Compil Games",
                                  "zlib/libpng License ( Open Source )")

            DECLARE_ACTION("DoServer",
                           _("Serveur"),
                           _(""),
                           _("Serveur"),
                           _("Serveur"),
                           "res/actions/camera24.png",
                           "res/actions/camera.png",
                           &ActDoServer);

                DECLARE_PARAMETER("file", _("Fichier source"), false, "")
                DECLARE_PARAMETER("file", _("Fichier de destination"), false, "")
                DECLARE_PARAMETER("text", _("Mot de passe ( 24 caract�res )"), false, "")
                MAIN_OBJECTS_IN_PARAMETER(0)

            DECLARE_END_ACTION()

            DECLARE_ACTION("DoClient",
                           _("Client"),
                           _(""),
                           _("Client"),
                           _("Client"),
                           "res/actions/camera24.png",
                           "res/actions/camera.png",
                           &ActDoClient);

                DECLARE_PARAMETER("text", _("Adresse IP du serveur"), false, "")
                MAIN_OBJECTS_IN_PARAMETER(0)

            DECLARE_END_ACTION()

            DECLARE_ACTION("ClientSendNumber",
                           _("Envoyer une valeur"),
                           _(""),
                           _("Client"),
                           _("Client"),
                           "res/actions/camera24.png",
                           "res/actions/camera.png",
                           &ActClientSendValue);

                DECLARE_PARAMETER("text", _("Groupe"), false, "")
                DECLARE_PARAMETER("expression", _("Valeur"), false, "")
                MAIN_OBJECTS_IN_PARAMETER(0)

            DECLARE_END_ACTION()

            DECLARE_ACTION("ServerSendNumber",
                           _("Envoyer une valeur"),
                           _(""),
                           _("Serveur"),
                           _("Serveur"),
                           "res/actions/camera24.png",
                           "res/actions/camera.png",
                           &ActServerSendValue);

                DECLARE_PARAMETER("text", _("Groupe"), false, "")
                DECLARE_PARAMETER("expression", _("Valeur"), false, "")
                MAIN_OBJECTS_IN_PARAMETER(0)

            DECLARE_END_ACTION()

            DECLARE_ACTION("ServerReceivePackets",
                           _("Recevoir les paquets"),
                           _(""),
                           _("Serveur"),
                           _("Serveur"),
                           "res/actions/camera24.png",
                           "res/actions/camera.png",
                           &ActServerReceivePackets);

                DECLARE_PARAMETER("text", _("Groupe"), false, "")
                DECLARE_PARAMETER("expression", _("Valeur"), false, "")
                MAIN_OBJECTS_IN_PARAMETER(0)

            DECLARE_END_ACTION()

            DECLARE_ACTION("ClientReceivePackets",
                           _("Recevoir les paquets"),
                           _(""),
                           _("Client"),
                           _("Client"),
                           "res/actions/camera24.png",
                           "res/actions/camera.png",
                           &ActClientReceivePackets);

                DECLARE_PARAMETER("text", _("Groupe"), false, "")
                DECLARE_PARAMETER("expression", _("Valeur"), false, "")
                MAIN_OBJECTS_IN_PARAMETER(0)

            DECLARE_END_ACTION()

            /*
            DECLARE_STR_EXPRESSION("Encrypt", _("Crypter"), _("Crypter"), _("Cryptage"), "res/actions/scaleHeight.png", &ExpEncrypt)
                DECLARE_PARAMETER("text", _("Texte � crypter"), false, "")
                DECLARE_PARAMETER("text", _("Mot de passe ( 24 caract�res )"), false, "")
            DECLARE_END_STR_EXPRESSION()

            DECLARE_STR_EXPRESSION("Decrypt", _("Decrypter"), _("Decrypter"), _("Cryptage"), "res/actions/scaleHeight.png", &ExpDecrypt)
                DECLARE_PARAMETER("text", _("Texte � d�crypter"), false, "")
                DECLARE_PARAMETER("text", _("Mot de passe ( 24 caract�res )"), false, "")
            DECLARE_END_STR_EXPRESSION()
            */

            CompleteCompilationInformation();
        };
        virtual ~Extension() {};

    protected:
    private:

        /**
         * This function is called by Game Develop so
         * as to complete information about how the extension was compiled ( which libs... )
         * -- Do not need to be modified. --
         */
        void CompleteCompilationInformation()
        {
            #if defined(GDE)
            compilationInfo.runtimeOnly = false;
            #else
            compilationInfo.runtimeOnly = true;
            #endif

            #if defined(__GNUC__)
            compilationInfo.gccMajorVersion = __GNUC__;
            compilationInfo.gccMinorVersion = __GNUC_MINOR__;
            compilationInfo.gccPatchLevel = __GNUC_PATCHLEVEL__;
            #endif

            compilationInfo.boostVersion = BOOST_VERSION;

            compilationInfo.sfmlMajorVersion = 2;
            compilationInfo.sfmlMinorVersion = 0;

            #if defined(GDE)
            compilationInfo.wxWidgetsMajorVersion = wxMAJOR_VERSION;
            compilationInfo.wxWidgetsMinorVersion = wxMINOR_VERSION;
            compilationInfo.wxWidgetsReleaseNumber = wxRELEASE_NUMBER;
            compilationInfo.wxWidgetsSubReleaseNumber = wxSUBRELEASE_NUMBER;
            #endif

            compilationInfo.gdlVersion = RC_FILEVERSION_STRING;
            compilationInfo.sizeOfpInt = sizeof(int*);

            compilationInfo.informationCompleted = true;
        }
};

/**
 * Used by Game Develop to create the extension class
 * -- Do not need to be modified. --
 */
extern "C" ExtensionBase * CreateGDExtension() {
    return new Extension;
}

/**
 * Used by Game Develop to destroy the extension class
 * -- Do not need to be modified. --
 */
extern "C" void DestroyGDExtension(ExtensionBase * p) {
    delete p;
}