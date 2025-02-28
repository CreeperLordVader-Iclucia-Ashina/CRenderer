#ifndef RENDERCRAFT_CORE_INCLUDE_CORE_SCENE_PARSER_H_
#define RENDERCRAFT_CORE_INCLUDE_CORE_SCENE_PARSER_H_
// for now I shall use pugixml, in the future I may use my own xml parser instead
#include <Core/scene.h>
#include <pugixml.hpp>
#include <memory>
#include <tuple>

namespace rdcraft {
#define USE_HARD_CODED_SCENE true
void parseCamera(pugi::xml_node node);
void parseLight(pugi::xml_node node);
void parsePrimitive(pugi::xml_node primitive);
#ifndef USE_HARD_CODED_SCENE
std::tuple<std::unique_ptr<Scene>, std::unique_ptr<Integrator>> loadScene(
    const char* file_path);
#else
std::tuple<std::unique_ptr<Scene>, std::unique_ptr<Integrator>> hardCodedScene(
    const std::string& output_path);
#endif
}
#endif