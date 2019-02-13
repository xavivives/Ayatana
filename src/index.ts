import sensorRegistryJson from "../static/sensorRegistry.json"
import { HttpServer } from "./httpServer"

console.log(sensorRegistryJson)
console.log('Starting Ayatana')
const httpServer = new HttpServer()
httpServer.start()

//setting up sensor registry

