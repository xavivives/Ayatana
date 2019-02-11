import koa from('koa')
import koaRouter from ('koaRouter')

const app = new koa()
const router = new koaRouter()

router.get('Ayatana', '/', (ctx)=>{
    ctx.body = 'Welcome! To llooasfasdfasdf'
})

app.use(router.routes())
.use(router.allowedMethods())

app.listen(123, ()=> console.log('running on port 1234'))