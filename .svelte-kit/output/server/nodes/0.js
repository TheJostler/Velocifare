import * as universal from '../entries/pages/_layout.js';

export const index = 0;
let component_cache;
export const component = async () => component_cache ??= (await import('../entries/pages/_layout.svelte.js')).default;
export { universal };
export const universal_id = "src/routes/+layout.js";
export const imports = ["_app/immutable/nodes/0.pi1VLsQK.js","_app/immutable/chunks/scheduler.7-y2jaZM.js","_app/immutable/chunks/index.MM7Gdo5C.js","_app/immutable/chunks/stores.mgUKY2hg.js","_app/immutable/chunks/entry.XBzyVE18.js","_app/immutable/chunks/index.8swplgdT.js"];
export const stylesheets = ["_app/immutable/assets/0.oZYpT5lw.css"];
export const fonts = ["_app/immutable/assets/fira-mono-cyrillic-ext-400-normal.dOGCK5uJ.woff2","_app/immutable/assets/fira-mono-all-400-normal.dpry7Ug7.woff","_app/immutable/assets/fira-mono-cyrillic-400-normal.N-vuOVMo.woff2","_app/immutable/assets/fira-mono-greek-ext-400-normal.rKiNtwjr.woff2","_app/immutable/assets/fira-mono-greek-400-normal.At854Oju.woff2","_app/immutable/assets/fira-mono-latin-ext-400-normal.-l34kfv6.woff2","_app/immutable/assets/fira-mono-latin-400-normal.yoy1YEIp.woff2"];
