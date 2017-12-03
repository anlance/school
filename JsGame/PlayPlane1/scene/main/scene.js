class Scene extends HaiScene{
    constructor(game) {
        super(game)
        this.setup()
        this.setupInputs()
    }
    // draw() {
    //     //draw labels
    //     // this.game.drawImage(this.bg)
    //     // this.game.drawImage(this.player)
    // }
    update() {
        super.update()
        this.cloud.update()
    }
    setup() {
        var game = this.game
        this.numberOfEnemies = 10
        this.bg = HaiImage.new(game, 'sky')
        this.cloud = Cloud.new(game, 'cloud')    
        // this.player = HaiImage.new(game, 'player')
        this.player = Player.new(game)
        this.player.x = 100
        this.player.y = 150

        this.addElement(this.bg)
        this.addElement(this.cloud)
        this.addElement(this.player)
        //

        this.addEnemies()
    }
    addEnemies() {
        var es = []
        for (var i = 0; i < this.numberOfEnemies; i++){
            var e = Enemy.new(this.game)
            es.push(e)
            this.addElement(e)
        }
        this.enemies = es
    }
    setupInputs() {
        var g = this.game
        var s = this
        g.registerAction('a', function () {
            s.player.moveLeft()
        })
        g.registerAction('d', function () {
            s.player.moveRight()
        })
        g.registerAction('w', function () {
            s.player.moveUp()
        })
        g.registerAction('s', function () {
            s.player.moveDown()
        })
        g.registerAction('j', function () {
            s.player.fire()
        })
    }
}

const config = {
    player_speed: 10,
    cloud_speed: 1,
    enemy_speed: 5,
    bullet_speed: 3,
    fire_cooldown: 9,
}