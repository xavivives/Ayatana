import * as nodeRegistryJson from "../static/sensorRegistry.json"
import { HttpServer } from "./httpServer"
import { NodeRegistry, INodeRegistry } from './nodeRegistry.js';

console.log(nodeRegistryJson)
console.log('Starting Ayatana')
const httpServer = new HttpServer()
httpServer.start()

const registry = new NodeRegistry()
const data = nodeRegistryJson as INodeRegistry
registry.popuplate(data)


//setting up sensor registry

