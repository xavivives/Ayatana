import * as Koa from 'koa'
import * as Router from 'koa-router'

export class HttpServer {

    private  app: Koa
    private  router: Router

    constructor() {
        this.app = new Koa()
        this.router = new Router()
        this.app.use(this.router.routes())
    }

    public start() {
        this.router.get('/*', async (ctx) => {
            console.log(ctx)
            ctx.body = 'Welcome! To llooasfasdfasdf'
        })

        this.app.listen(3000)
        console.log("server running on port 3000")
    }
}