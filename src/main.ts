import * as Koa from 'koa'
import * as Router from 'koa-router'

const app = new Koa()
const router = new Router()

router.get( '/*', async(ctx)=>{
	console.log(ctx)
    ctx.body = 'Welcome! To llooasfasdfasdf'
})

app.use(router.routes())



app.listen(3000)
console.log("server running on port 3000")