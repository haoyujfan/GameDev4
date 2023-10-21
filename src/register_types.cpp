#include "register_types.h"
#include "player.h"
#include "cactus.h"
#include "food.h"
#include "ground.h"
#include "camera.h"
#include "raycast.h"
#include "attacker.h"
#include "eater.h"
#include "eater_fsm.h"
#include "state.h"
#include "eatereat.h"
#include "eaterchase.h"
#include "eaterretreat.h"
#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_player_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
    ClassDB::register_class<Player>();
    ClassDB::register_class<Cactus>();
    ClassDB::register_class<Food>();
    ClassDB::register_class<Ground>();
    ClassDB::register_class<Camera>();
    ClassDB::register_class<Raycast>();
    ClassDB::register_class<State>();
    ClassDB::register_class<Eater>();
    ClassDB::register_class<EaterFSM>();
    ClassDB::register_class<EaterEat>();
    ClassDB::register_class<EaterChase>();
    ClassDB::register_class<EaterRetreat>();
    ClassDB::register_class<Attacker>();
}

void uninitialize_player_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT player_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
    godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

    init_obj.register_initializer(initialize_player_module);
    init_obj.register_terminator(uninitialize_player_module);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

    return init_obj.init();
}
}
