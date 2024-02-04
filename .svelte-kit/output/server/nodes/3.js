import * as universal from '../entries/pages/about/_page.js';

export const index = 3;
let component_cache;
export const component = async () => component_cache ??= (await import('../entries/pages/about/_page.svelte.js')).default;
export { universal };
export const universal_id = "src/routes/about/+page.js";
export const imports = ["_app/immutable/nodes/3.Ei85LAAH.js","_app/immutable/chunks/index.30ImaL5r.js","_app/immutable/chunks/scheduler.7-y2jaZM.js","_app/immutable/chunks/index.MM7Gdo5C.js"];
export const stylesheets = [];
export const fonts = [];
