import * as universal from '../entries/pages/_page.js';

export const index = 2;
let component_cache;
export const component = async () => component_cache ??= (await import('../entries/pages/_page.svelte.js')).default;
export { universal };
export const universal_id = "src/routes/+page.js";
export const imports = ["_app/immutable/nodes/2.MZv34Arl.js","_app/immutable/chunks/scheduler.7-y2jaZM.js","_app/immutable/chunks/index.MM7Gdo5C.js","_app/immutable/chunks/index.8swplgdT.js"];
export const stylesheets = ["_app/immutable/assets/2.rPCkfgW1.css"];
export const fonts = [];
