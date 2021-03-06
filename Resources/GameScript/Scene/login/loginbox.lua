--[[

登录框

]]
local START, REGISTER, MANAGER = 1, 2, 3 
local PATH = IMG_SCENE.."login/"
local M = {
	layer,
	optLayer,
	account,
	password
}

function M:create( ... )
	local this = {}
	setmetatable(this,self)
	self.__index = self
	
	this.layer = CCLayer:create()
	
	local bg = newSprite(IMG_SCENE.."login/login_bg.jpg")
	setAnchPos(bg, 0, 0)
	this.layer:addChild(bg)

	--[[创建输入框]]
	this.account = CCTextFieldTTF:textFieldWithPlaceHolder("Open ID" , "Thonburi" , 48);
	this.account:setString("web")
	--[[设置颜色]]
	this.account:setColor( ccc3(255 , 255 , 0) )
	this.account:setColorSpaceHolder( ccc3(255 , 255 , 0) )

	display.align(this.account , display.CENTER , display.cx , display.cy + 100)
	this.layer:addChild( this.account )


	--[[绑定事件]]
	local onAttachWithIME = true
	this.account:attachWithIME()
	this.layer:registerScriptTouchHandler( function()
		if onAttachWithIME then
			echoLog("Login" , "detachWithIME")

			this.account:detachWithIME()
			onAttachWithIME = false
		else
			echoLog("Login" , "attachWithIME")

			this.account:attachWithIME()
			onAttachWithIME = true
		end

		return false
	end )
	this.layer:setTouchEnabled( true )




	
--跳 过按钮


	local exit = Btn:new(IMG_SCENE.."fighting/",{"fighting_quit.png"},420,800,{
		scale = true,
		priority = -199,
		callback = 
		function()
			switchScene("fighting")
		end})
	this.layer:addChild(exit:getLayer())
	
	this:createOptBox(START)
	return this.layer
end

function M:createOptBox(state)
	if self.optLayer then
		self.layer:removeChild(self.optLayer,true)
		self.optLayer = nil
	end
	
	if state then	
		self.optLayer = CCLayer:create()
		
		local bg = newSprite(PATH.."login_opt_bg.png")
		setAnchPos(bg, 240, 425, 0.5, 0.5)
		self.optLayer:addChild(bg)
		
		local opt	
		--根据选择的操作 创建对应的布局与功能按钮
		if state == START then
			opt = {
				{"register",
					function()
						self:createOptBox(REGISTER)
					end
				},
				{"login", -- 点击登陆按钮，则隐藏操作 选框并生成账号输入界面
					function()
						self:createOptBox()
						self:accountInput()
					end
				},
				{"manager",
					function()
						self:createOptBox(MANAGER)
					end
				}
			}
			
			local y = 550
			for i = 1, #opt do
				local optBtn = Btn:new(IMG_BTN,{"btn_bg_login.png", "btn_bg_login_press.png"},100,y,{
					front = {IMG_TEXT..opt[i][1]..".png", IMG_TEXT..opt[i][1].."_press.png"},
					callback = opt[i][2]
				})
				self.optLayer:addChild(optBtn:getLayer())
				y = y - 150
			end
		elseif state == REGISTER then
			
		elseif state == MANAGER then
		
		end 
		
		self.layer:addChild(self.optLayer)
	end
end

function M:accountInput()
	if self.optLayre then
		self.layer:removeChild(self.optLayer,true)
	end
	self.optLayer = CCLayer:create()
	
	
	
	local accountText = newSprite(IMG_TEXT.."account_text.png")
	setAnchPos(accountText,10,500)
	self.optLayer:addChild(accountText)
	
	accountText = newSprite(PATH.."input_bg.png")
	setAnchPos(accountText,120,480)
	self.optLayer:addChild(accountText)
	
	
	local pwdText = newSprite(IMG_TEXT.."password_text.png")
	setAnchPos(pwdText,10,420)
	self.optLayer:addChild(pwdText)
	
	pwdText = newSprite(PATH.."input_bg.png")
	setAnchPos(pwdText,120,400)
	self.optLayer:addChild(pwdText)
--	
--	local remindPwd = CheckBox:new(100,350,{file = {}})
--	self.optLayer:addChild(remindPwd:getLayer())
--	
--	local autoLogin = CheckBox:new(100,350,{file = {}})
--	self.optLayer:addChild(autoLogin:getLayer())
	
	
	local login_button = Btn:new(IMG_BTN,{"login_opt.png", "login_opt_press.png"},150,100,{
		callback = 
		function()
			local open_id = self.account:getString()
			open_id = string.trim( open_id )
			if open_id == "" then
				KNMsg:getInstance():flashShow("请输入OPEN ID")
				return
			end
			HTTPS:send("Landed" , {m="login",a="develop",open_id = open_id} )    -- 登录
		end})
	self.optLayer:addChild(login_button:getLayer())
	
	self.layer:addChild(self.optLayer)
end

return M
