class HaiGame{
    constructor(fps, images, runCallback) {
        window.fps = fps
        this.images = images
        this.runCallback = runCallback
        //
        this.scene = null
        this.actions = {}
        this.keydowns = {}
        this.canvas = document.querySelector('#id-canvas')
        this.context = this.canvas.getContext('2d')
        var self =this
        window.addEventListener('keydown',function(event){
            self.keydowns[event.key] = true
        })
        window.addEventListener('keyup',event => {
            this.keydowns[event.key] = false
        })
        this.init()
    }
    static instance(...args) {
        this.i = this.i || new this(...args)
        return this.i
    }
    //draw
    drawImage(img) {
        this.context.drawImage(img.image,img.x,img.y)
    }
     //updat
     update() {
        this.scene.update()
    }
    //draw
    draw() {
        this.scene.draw()
    }
    registerAction(key,callback){
        this.actions[key] = callback
    }
    //timer
    runloop() {
        var g = this
        var actions = Object.keys(g.actions)
        for(var i=0;i<actions.length;i++){
            var key = actions[i]
            if(g.keydowns[key]){
                //如果按键被按下，调用注册的action
                g.actions[key]()
            }
        }
        //update
        g.update()
        //clear
        g.context.clearRect(0,0,g.canvas.width,g.canvas.height)        
        //draw
        g.draw()
        //next runloop
        setTimeout(function(){
            //events
            g.runloop()
        }, 1000 / window.fps)
    }
    init() {
        var g = this
        //预先加载所有图片
        var loads = []
        //
        var names = Object.keys(g.images)
        for (var i = 0; i < names.length; i++){
            let name = names[i]
            var path = g.images[name]
            let img = new Image()
            img.src = path
            img.onload = function () {
                //存入g.images 中
                g.images[name] = img
                //所有图片载入成功后，调用run
                loads.push(1)
                log('loadsimages',loads.length,names.length)
                if (loads.length == names.length) {
                    g.run()
                }
            }
        }
    }
    imageByName(name) {
        var g = this
        var img = g.images[name]
        var image = {
            w: img.width,
            h: img.height,
            image: img,
        }
        return image
    }
    runWithScene(scene) {
        var g = this
        this.scene = scene
        setTimeout(function(){
            //events
            g.runloop()
        }, 1000 / window.fps)
    }
    replaceScene(scene) {
        this.scene = scene
    }
    run() {
        this.runCallback(this)
        //开始运行程序
        
    }
}
