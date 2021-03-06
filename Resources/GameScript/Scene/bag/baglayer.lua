local PATH = "bag/"
local ITEM = require(SRC.."Scene/common/ItemInfo")
local Detail = require(SRC.."Scene/common/CardDetail")

local M = {
	layer,
	listLayer,
	tabGroup
}

function M:create( ... )
	local this = {}
	setmetatable(this,self)
	self.__index = self
	
	this.layer = CCLayer:create()
	
	local bg = newSprite(IMG_COMMON.."main.png")
	setAnchPos(bg, 0, 80)
	this.layer:addChild(bg)
	
	this.tabGroup = RadioGroup:new()
	
	local tabs = {
		{"equip"},
		{"hero"},
		{"skill"},
		{"prop"}
	}
	
	local x = 12
	for k, v in pairs(tabs) do
		local btn = Btn:new(IMG_COMMON.."tabs/", {"tab_"..v[1]..".png", "tab_"..v[1].."_select.png"}, x, 668, { 
			callback = function()
				this:createList(v[1])
			end
		},this.tabGroup)
		this.layer:addChild(btn:getLayer())		
		x = x + btn:getWidth() + 5 
	end
	
	local separator = newSprite(IMG_COMMON.."tabs/tab_separator.png")
	setAnchPos(separator,0,667)
	this.layer:addChild(separator)
	
	this.tabGroup:chooseByIndex(1,true)

	this.layer:addChild(InfoLayer:create():getLayer())
	return this.layer
end

function M:createList(kind)
	if self.listLayer then
		self.layer:removeChild(self.listLayer,true)
	end
	self.listLayer = CCLayer:create()
	
	local scroll = ScrollView:new(0,90,480,575,5)
	local temp
	for k, v in pairs(DATA_Bag:get(kind)) do
		local item 
		item = ITEM:new(kind,v["cid"],{
			parent = scroll,	
			type = "bag",
			iconCallback = function()
				self.layer:addChild(Detail:new(kind,v["cid"]):getLayer(),1)
			end
		})
		scroll:addChild(item:getLayer(),item)
	end
	scroll:alignCenter()
	
	self.listLayer:addChild(scroll:getLayer())
	self.layer:addChild(self.listLayer)
end

return M
