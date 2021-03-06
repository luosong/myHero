local Item = require(SRC.."Scene/common/ItemInfo")
local ItemList = {
	layer,
	scroll,
	params
}

function ItemList:new(params)
	local this = {}
	setmetatable(this,self)
	self.__index = self
	
	this.params = params or {}
	
	local itemLayer = newLayer()
	local bg = newSprite(IMG_COMMON.."list_bg.png")
	setAnchPos(bg)
	itemLayer:addChild(bg)
	
	this.scroll = ScrollView:new(0,160,480,555,5)
	local temp
	for k, v in pairs(DATA_Bag:get("equip")) do
		local item 
		item = Item:new("equip",v["cid"],{
			parent = this.scroll,	
			iconCallback = function()
				self.layer:addChild(Detail:new(kind,v["cid"]):getLayer(),1)
			end
		})
		this.scroll:addChild(item:getLayer(),item)
	end
	this.scroll:alignCenter()
	itemLayer:addChild(this.scroll:getLayer())
	
	local okBtn = Btn:new(IMG_BTN,{"ok.png", "ok_press.png"}, 200, 95, {
		priority = -131,
		callback = function()
			this.params.okCallback()
			this.layer:removeFromParentAndCleanup(true)	
		end
	})
	itemLayer:addChild(okBtn:getLayer())
	
	local cancelBtn = Btn:new(IMG_BTN,{"cancel.png", "cancel_press.png"}, 350, 95, {
		priority = -131,
		callback = function()
			this.layer:removeFromParentAndCleanup(true)	
		end
	})
	itemLayer:addChild(cancelBtn:getLayer())
	
	local sortBtn = Btn:new(IMG_BTN,{"sort.png", "sort_press.png"}, 10, 735, {
		priority = -131,
		callback = function()
		end
	})
	itemLayer:addChild(sortBtn:getLayer())
	
	local ruleBtn = Btn:new(IMG_BTN,{"all_star.png", "all_star_press.png"}, 380, 735, {
		priority = -131,
		callback = function()
		end
	})
	itemLayer:addChild(ruleBtn:getLayer())
	
	
	this.layer = Mask:new({item = itemLayer})
	
	return this
end

function ItemList:getLayer()
	return self.layer
end

return ItemList