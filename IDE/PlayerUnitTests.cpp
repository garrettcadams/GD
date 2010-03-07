#include "CppUnitLite/TestHarness.h"
#include "GDL/Object.h"
#include "GDL/aMove.h"
#include "GDL/cMove.h"
#include "GDL/Access.h"
#include "GDL/ObjectsConcerned.h"
#include <boost/shared_ptr.hpp>
#include <string>
#include <vector>
#include "GDL/SpriteObject.h"
#include "GDL/Object.h"
#include "GDL/RuntimeGame.h"

#include "windows.h"
#ifdef ___WXMSW___
#include <wx/msw/winundef.h>
#endif

using namespace std;

TEST( Player, ObjectsConcerned )
{
    ObjInstancesHolder objectsList;
    objectsList.AddObject(boost::shared_ptr<Object>(new Object("blueBall")));
    objectsList.AddObject(boost::shared_ptr<Object>(new Object("blueBall")));
    objectsList.AddObject(boost::shared_ptr<Object>(new Object("redBall")));
    objectsList.AddObject(boost::shared_ptr<Object>(new Object("blueSquare")));
    objectsList.AddObject(boost::shared_ptr<Object>(new Object("redSquare")));
    objectsList.AddObject(boost::shared_ptr<Object>(new Object("redSquare")));
    objectsList.AddObject(boost::shared_ptr<Object>(new Object("blueAutre")));

    vector < ObjectGroup > groupsList;
    groupsList.push_back(ObjectGroup());
    groupsList.push_back(ObjectGroup());
    groupsList.push_back(ObjectGroup());
    groupsList.push_back(ObjectGroup());
    groupsList.push_back(ObjectGroup());

    groupsList[0].SetName("Balls");
    groupsList[0].AddObject("blueBall");
    groupsList[0].AddObject("redBall");

    groupsList[1].SetName("Squares");
    groupsList[1].AddObject("blueSquare");
    groupsList[1].AddObject("redSquare");

    groupsList[2].SetName("Blues");
    groupsList[2].AddObject("blueSquare");
    groupsList[2].AddObject("blueBall");
    groupsList[2].AddObject("blueAutre");

    groupsList[3].SetName("Reds");
    groupsList[3].AddObject("redSquare");
    groupsList[3].AddObject("redBall");

    groupsList[4].SetName("Other");
    groupsList[4].AddObject("blueAutre");

    ObjectsConcerned objectsConcerned(&objectsList, &groupsList);

    ObjectIdentifiersManager * objectIdentifiersManager = ObjectIdentifiersManager::getInstance();

    {
        vector < boost::shared_ptr<Object> > picked;

        picked = objectsConcerned.Pick(objectIdentifiersManager->GetOIDfromName("Reds"));
        CHECK_EQUAL(3L, (long)picked.size()); // Les 3 rouges
        CHECK_EQUAL(3L, (long)objectsConcerned.objectsPicked.GetAllObjects().size()); // Les 3 rouges
        for (unsigned int i = 0;i<picked.size();++i)
            cout << "object concerned : " << picked[i]->GetName() << endl;
        cout << endl;
        for (unsigned int i = 0;i<objectsConcerned.objectsPicked.GetAllObjects().size();++i)
            cout << "object Picked : " << objectsConcerned.objectsPicked.GetAllObjects()[i]->GetName() << endl;
        cout << endl;
        cout << "------------------" <<endl;
        cout << endl;

        picked = objectsConcerned.Pick(objectIdentifiersManager->GetOIDfromName("Squares"));
        CHECK_EQUAL(2L, (long)picked.size());// Les deux carr�s rouge
        CHECK_EQUAL(3L, (long)objectsConcerned.objectsPicked.GetAllObjects().size()); // Les 3 rouges
        for (unsigned int i = 0;i<picked.size();++i)
            cout << "object concerned : " << picked[i]->GetName() << endl;
        cout << endl;
        for (unsigned int i = 0;i<objectsConcerned.objectsPicked.GetAllObjects().size();++i)
            cout << "object Picked : " << objectsConcerned.objectsPicked.GetAllObjects()[i]->GetName() << endl;
        cout << endl;
        cout << "------------------" <<endl;

        picked = objectsConcerned.Pick(objectIdentifiersManager->GetOIDfromName("Other"));
        CHECK_EQUAL(1L, (long)picked.size()); //L'autre
        CHECK_EQUAL(4L, (long)objectsConcerned.objectsPicked.GetAllObjects().size()); // Les 3 rouges et l'autre
        for (unsigned int i = 0;i<picked.size();++i)
            cout << "object concerned : " << picked[i]->GetName() << endl;
        cout << endl;
        for (unsigned int i = 0;i<objectsConcerned.objectsPicked.GetAllObjects().size();++i)
            cout << "object Picked : " << objectsConcerned.objectsPicked.GetAllObjects()[i]->GetName() << endl;
        cout << endl;
        cout << "------------------" <<endl;

        picked = objectsConcerned.PickAndRemove(objectIdentifiersManager->GetOIDfromName("Reds"));
        CHECK_EQUAL(3L, (long)picked.size()); // Les 3 rouges
        CHECK_EQUAL(1L, (long)objectsConcerned.objectsPicked.GetAllObjects().size()); // L'autre
        cout << endl;

        //Print concerned and picked objects
        for (unsigned int i = 0;i<picked.size();++i)
            cout << "object concerned : " << picked[i]->GetName() << endl;
        cout << endl;
        for (unsigned int i = 0;i<objectsConcerned.objectsPicked.GetAllObjects().size();++i)
            cout << "object Picked : " << objectsConcerned.objectsPicked.GetAllObjects()[i]->GetName() << endl;
        cout << endl;
    }

}

TEST( Player, Forces )
{
    Force force;
    force.SetX(500);
    force.SetY(0);

    CHECK_EQUAL(0L, force.GetAngle());
    CHECK_EQUAL(long(int(499.997833)), long(int(force.GetLength())));

    force.SetAngle(90);
    force.SetLength(5);

    CHECK_EQUAL(0.0, long(int(force.GetX())));
    CHECK_EQUAL(5L, force.GetY());
}


TEST( Player, actionsMove )
{
    Object * object = new Object("testobj");

    Force force;
    force.SetX(500);
    force.SetY(0);
    object->Forces.push_back(force);

    sf::RenderWindow unusedWin;
    RuntimeGame game;

    RuntimeScene scene(&unusedWin, &game);
    scene.objectsInstances.AddObject(boost::shared_ptr<Object>(object));
}

TEST( Player, conditionsMove )
{
    Object * object = new Object("testobj");

    Force force;
    force.SetX(0);
    force.SetY(0);
    object->Forces.push_back(force);

    sf::RenderWindow unusedWin;
    RuntimeGame game;

    RuntimeScene scene(&unusedWin, &game);
    scene.objectsInstances.AddObject(boost::shared_ptr<Object>(object));

    //Condition Un objet est � l'arr�t
    vector < int > objConcern;
    Instruction condition;
    vector < GDExpression > params;
    params.push_back(GDExpression("testobj"));
    condition.SetParameters(params);
    condition.SetLocal(false);
    condition.SetInversion(false);
    Evaluateur eval(game, scene);
    ObjectsConcerned objectsConcerned(&scene.objectsInstances, &scene.objectGroups);
    eval.SetObjectsConcerned(&objectsConcerned);

}
