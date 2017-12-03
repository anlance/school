class Player extends HaiImage{
    constructor(game) {
        super(game, 'player')
        this.setup()
    }
    setup() {
        this.speed = 5
        this.cooldown = 0
    }
    update() {
        this.speed = config.player_speed
        if (this.cooldown > 0) {
            this.cooldown--
        }
    }
    fire() {
        this.update()   //他没有这一句也成功了-。-！！
        if (this.cooldown == 0) {
            this.cooldown = config.fire_cooldown          
            var x = this.x //+ this.w / 2
            var y = this.y
            var b = Bullet.new(this.game)
            b.x = x
            b.y = y
            this.scene.addElement(b)
        }
    }
    moveLeft() {
        this.x -= this.speed 
    }
    moveRight() {
        this.x += this.speed 
    }
    moveUp() {
        this.y -= this.speed 
    }
    moveDown() {
        this.y += this.speed 
    }
}