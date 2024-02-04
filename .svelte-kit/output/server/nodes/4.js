import * as server from '../entries/pages/sverdle/_page.server.js';

export const index = 4;
let component_cache;
export const component = async () => component_cache ??= (await import('../entries/pages/sverdle/_page.svelte.js')).default;
export { server };
export const server_id = "src/routes/sverdle/+page.server.js";
export const imports = ["_app/immutable/nodes/4.YG1a6z-H.js","_app/immutable/chunks/scheduler.7-y2jaZM.js","_app/immutable/chunks/index.MM7Gdo5C.js","_app/immutable/chunks/entry.XBzyVE18.js","_app/immutable/chunks/index.8swplgdT.js"];
export const stylesheets = ["_app/immutable/assets/4.zpJKtCAG.css"];
export const fonts = [];
