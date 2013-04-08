
CCSceneExtend = class("CCSceneExtend", CCNodeExtend)
CCSceneExtend.__index = CCSceneExtend

function CCSceneExtend.extend(target)
    local t = tolua.getpeer(target)
    if not t then
        t = {}
        tolua.setpeer(target, t)
    end
    setmetatable(t, CCSceneExtend)

    local function handler(event)
        if event["name"] == "enter" then
            echoLog("Scene" , target.name .. " onEnter()")
            target:onEnter()
        elseif event["name"] == "exit" then
            echoLog("Scene" , target.name .. " onExit()")

            if target.AUTO_CLEANUP_IMAGES then
                for imageName, v in pairs(target.AUTO_CLEANUP_IMAGES) do
                    display.removeSpriteFrameByImageName(imageName)
                end
                target.AUTO_CLEANUP_IMAGES = nil
            end

            target:onExit()
        end
    end
    target:registerScriptHandler(handler)

    return target
end

function CCSceneExtend:onEnter()
end

function CCSceneExtend:onExit()
end

function CCSceneExtend:addAutoCleanImage(imageName)
    if not self.AUTO_CLEANUP_IMAGES then self.AUTO_CLEANUP_IMAGES = {} end
    self.AUTO_CLEANUP_IMAGES[imageName] = true
end
