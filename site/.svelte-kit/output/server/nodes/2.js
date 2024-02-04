

export const index = 2;
let component_cache;
export const component = async () => component_cache ??= (await import('../entries/pages/_page.svelte.js')).default;
export const imports = ["_app/immutable/nodes/2.bVWEJjcs.js","_app/immutable/chunks/scheduler.zMJaRgub.js","_app/immutable/chunks/index.ZLPrqq-8.js"];
export const stylesheets = [];
export const fonts = [];
