/*
 * Game Develop Core
 * Copyright 2008-2014 Florian Rival (Florian.Rival@gmail.com). All rights reserved.
 * This project is released under the GNU Lesser General Public License.
 */
#include "AllBuiltinExtensions.h"
#include "GDCore/Tools/Localization.h"
#if defined(GD_IDE_ONLY)
#include "GDCore/Events/Event.h"
#include "GDCore/Events/Builtin/StandardEvent.h"
#include "GDCore/Events/Builtin/CommentEvent.h"
#include "GDCore/Events/Builtin/ForEachEvent.h"
#include "GDCore/Events/Builtin/WhileEvent.h"
#include "GDCore/Events/Builtin/RepeatEvent.h"
#include "GDCore/Events/Builtin/LinkEvent.h"
#endif

using namespace std;
namespace gd
{

void GD_CORE_API BuiltinExtensionsImplementer::ImplementsCommonInstructionsExtension(gd::PlatformExtension & extension)
{
    extension.SetExtensionInformation("BuiltinCommonInstructions",
                          _("Standard events"),
                          _("Built-in extension providing standard events."),
                          "Florian Rival",
                          "Freeware");

#if defined(GD_IDE_ONLY)
    extension.AddCondition("Or",
               _("Or"),
               _("Return true if one of the sub conditions is true"),
               _("If one of these conditions is true:"),
               _("Advanced"),
               "res/conditions/or24.png",
               "res/conditions/or.png")
        .SetCanHaveSubInstructions()
        .MarkAsAdvanced();

    extension.AddCondition("And",
               _("And"),
               _("Return true if all sub conditions are true"),
               _("If all of these conditions are true:"),
               _("Advanced"),
               "res/conditions/and24.png",
               "res/conditions/and.png")
        .SetCanHaveSubInstructions()
        .MarkAsAdvanced();

    extension.AddCondition("Not",
               _("Not"),
               _("Return the contrary of the result of the sub conditions"),
               _("Invert the logical result of these conditions:"),
               _("Advanced"),
               "res/conditions/not24.png",
               "res/conditions/not.png")
        .SetCanHaveSubInstructions()
        .MarkAsAdvanced();

    extension.AddCondition("Once",
               _("Trigger once while true"),
               _("Run actions only once, for each time the conditions have been met."),
               _("Trigger once"),
               _("Advanced"),
               "res/conditions/once24.png",
               "res/conditions/once.png");

    extension.AddEvent("Standard", _("Standard event"),
              _("Standard event: Actions are run if conditions are fulfilled."),
              "", "res/eventaddicon.png",
              boost::shared_ptr<gd::BaseEvent>(new gd::StandardEvent));

    extension.AddEvent("Link", _("Link"),
              _("Link to some external events"),
              "", "res/lienaddicon.png",
              boost::shared_ptr<gd::BaseEvent>(new gd::LinkEvent));

    extension.AddEvent("Comment", _("Comment"),
              _("Event displaying a text in the events editor"),
              "", "res/comment.png",
              boost::shared_ptr<gd::BaseEvent>(new gd::CommentEvent));

    extension.AddEvent("While", _("While"),
              _("The event is repeated while the conditions are true"),
              "", "res/while.png",
              boost::shared_ptr<gd::BaseEvent>(new gd::WhileEvent));

    extension.AddEvent("Repeat", _("Repeat"),
              _("Event repeated a number of times"),
              "", "res/repeat.png",
              boost::shared_ptr<gd::BaseEvent>(new gd::RepeatEvent));

    extension.AddEvent("ForEach", _("For each object"),
              _("Repeat the event for each specified object."),
              "", "res/foreach.png",
              boost::shared_ptr<gd::BaseEvent>(new gd::ForEachEvent));
#endif
}

}