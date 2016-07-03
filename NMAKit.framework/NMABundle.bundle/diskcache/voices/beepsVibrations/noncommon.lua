-- ----------------------------------------------------------------------------
-- Copyright (C) 2009 Nokia Gate5 GmbH Berlin
--
-- These coded instructions, statements, and computer programs contain
-- unpublished proprietary information of Nokia Gate5 GmbH Berlin, and
-- are copy protected by law. They may not be disclosed to third parties
-- or copied or duplicated in any form, in whole or in part, without the
-- specific, prior written permission of Nokia Gate5 GmbH Berlin.
-- ----------------------------------------------------------------------------

-- ----------------------------------------------------------------------------

function get_common_code( )

    -- Pedestrian command
    if trigger == "PEDESTRIAN_COMMAND" then
        table.insert(result_list, misc[ "beep_sound" ] )   
    end
    
    if trigger == "ROUTE_RECALCULATION" then
        -- "Route recalculation"
        table.insert( result_list, misc[ "beep_sound" ] )
    end

end

