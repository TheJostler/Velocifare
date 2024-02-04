import * as universal from '../entries/pages/sverdle/how-to-play/_page.js';

export const index = 5;
let component_cache;
export const component = async () => component_cache ??= (await import('../entries/pages/sverdle/how-to-play/_page.svelte.js')).default;
export { universal };
export const universal_id = "src/routes/sverdle/how-to-play/+page.js";
export const imports = ["_app/immutable/nodes/5.CwK8ow1r.js","_app/immutable/chunks/index.30ImaL5r.js","_app/immutable/chunks/scheduler.7-y2jaZM.js","_app/immutable/chunks/index.MM7Gdo5C.js"];
export const stylesheets = ["_app/immutable/assets/5.lOqbKfPA.css"];
export const fonts = [];
